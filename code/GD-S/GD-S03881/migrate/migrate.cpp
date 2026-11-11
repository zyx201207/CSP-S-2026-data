#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,T,res,cnt;
ll n,d,ans,a[N];
void dfs(int u,int tar,int steps){
	if(steps>res) return;
	if(u==tar){
		if(steps==res) cnt++;
		if(steps<res) cnt=1,res=steps;
		return;
	}
	for(int v=u+1;v<=tar;v++){
		if(a[v]-a[u]>d) break;
		if(a[v]-a[u]<=d) dfs(v,tar,steps+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				res=N,cnt=0;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
