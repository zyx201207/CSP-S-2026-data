#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005];
long long maxi=-1;
bool vis[200005];

inline void f(long long ans,long long k){
	if(k==m){
		maxi=max(maxi,ans);
//		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
//			nin=i;
			vis[i]=1;
			f(ans&a[i],k+1);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	f((2ll<<32)-1,0);
	cout<<maxi;
//	cout<<(31&15&7);
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12

*/
