#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,d;
int a[2000005],h[2000005];
int minn=1000000005;
void dfs(int x,int ed,int stp){
	if(stp>=minn) return;
	if(x>=ed){
		h[stp]++;
		minn=min(minn,stp);
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]<=a[x]+d){
			dfs(i,ed,stp+1);
		}
	}
}
int f(int st){
	int ans=0;
	for(int i=st+1;i<=n;i++){
		minn=1000000005;
		dfs(st,i,0);
		if(h[minn]==2){
			ans++;
		}
		memset(h,0,sizeof h);
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(h,0,sizeof h);
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=f(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
