#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int a[N],pre[N];
ll n,m;
bool check(int x){
	ll res=0;
	for(int i=1;i<x;i++)res=res+(a[x]-a[i]);
	return res<=m;
}

void solve(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=-1;
	sort(a+1,a+n+1);
	if(n<=5000){
		int l=1,r=n;
		while(l<=r){
			int mid=l+r>>1;
			int c=check(mid);
			if(c){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		cout<<ans;	
	}
	else if(m<=1e8){
		map<int,int>cnt;
		map<int,int>pre,pre2;
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		for(int i=-101;i<=100;i++)pre[i]=pre[i-1]+cnt[i],pre2[i]=pre2[i-1]+cnt[i]*i;
		ll res=0;
		for(int i=-100;i<=100;i++){
			ll now=cnt[i];
			for(int j=i-1;j>=-100;j--){
				if((i-j)*cnt[j]<=m)now+=cnt[j];
				else {
					now=now+(m/(i-j));
					break;
				}
			}
			ans=max(ans,now);
		}
		cout<<ans;
	}
	else {
		int p=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(i*(i-1)<=(2*m)/p)ans=i;
		}
		cout<<ans;
	}
	
	
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
} 
