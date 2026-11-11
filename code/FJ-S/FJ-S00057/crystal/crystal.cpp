#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],cnt[N],ans,lastans;
bool st[N],flagA=1,flagB=1;
void dfs(long long now,long long anss,long long sum,long long mid){
	if(sum<0){
		ans=max(ans,anss-1);
		return ;
	}
	if(sum==0){
		ans=max(ans,anss);
		return;
	}
	if(now==mid){
		ans=max(ans,anss);
		return;
	}
	dfs(now+1,anss+1,sum-(a[mid]-a[now]),mid);
	dfs(now+1,anss,sum,mid);
}
bool check(long long mid){
	ans=0;
	dfs(1,cnt[a[mid]],m,mid);
	if(ans>lastans){
		lastans=ans;
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flagA=0;
		cnt[a[i]]++;
	} 
	sort(1+a,1+n+a);
	long long d=a[2]-a[1];
	for(int i=3;i<=n;i++) if(a[i]-a[i-1] != d) flagB=0;
	if(flagA){
		long long sum=0;
		for(long long i=n;i>=1;i--){
			sum+=n-i+1;
			if(sum==m){
				cout<<n-i+2;
				return 0;
			}
			if(sum>m){
				cout<<n-i+1;
				return 0;
			}
		}
	}
	if(flagB){
		long long sum=0;
		for(int i=n;i>=1;i--){
			sum+=(n-i+1)*d;
			if(sum==m){
				cout<<n-i+2;
				return 0;
			}
			if(sum>m){
				cout<<n-i+1;
				return 0;
			}
		}
	}
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<lastans;
	return 0;
}
