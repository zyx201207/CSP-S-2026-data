#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long a[maxn];
long long s[maxn][33];
long long sum[maxn];
bool vis[maxn];
int m,n;
bool check(long long mid){
	long long mx=mid,cnt=0;
	for(int i=0;i<n;i++){
		if((mid&a[i])==mid){
			cnt++;
		}
	}
	return cnt>=m;
}
long long solve(){
	long long l=1,r=(1<<30),ans=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=1){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ALL=(1<<n)-1;
		long long mx=0;
		for(int S=0;S<=ALL;S++){
			int t=__builtin_popcount(S);
			if(t!=m) continue;
			long long cnt=(1ll<<32)-1;
			for(int i=0;i<n;i++){
				if(((S>>i)&1)) cnt&=a[i];
			}
			mx=max(mx,cnt);
		}
		cout<<mx<<"\n";
	}else{
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		cout<<solve()<<"\n";
	}
	
	return 0;
}

