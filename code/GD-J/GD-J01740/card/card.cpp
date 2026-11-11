#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define x first
#define y second
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
int n,m,a[1000005],stk[1000005],tp,R[1000005];
int vis[1000005],ans[1000005],r[1000005];
int mp[1000005];
signed main(){
	fre("card");
	cin>>n>>m;
	bool xza=1;
	rep(i,1,n){
		cin>>a[i];
		if(vis[a[i]]) r[vis[a[i]]]=i;
		vis[a[i]]=i;
	}
	rep(i,1,n-1) if(a[i]>a[i+1]){xza=0;}
	if(xza){rep(i,1,m) cout<<vis[i]<<" ";exit(0);}
	rep(i,1,n) R[i]=vis[a[i]];
	rep(i,1,n){if(!r[i]) r[i]=i;vis[i]=0;}
	rep(i,1,n) mp[R[i]]++;
	rep(i,1,n) if(mp[i]){
		if(r[i]==i){mp[i+1]+=mp[i];ans[a[i]]+=mp[i];continue;}
		vector<int>v;
		for(int j=i;j<=n;j=max(r[j],j+1)) if(!vis[a[j]])
			vis[a[j]]=1,v.push_back(a[j]);
		for(auto j:v) ans[j]+=mp[i],vis[j]=0;
	}//O(nm)?
	rep(i,1,m) cout<<ans[i]<<" ";
}

