#include <bits/stdc++.h>
#define name "hub"
using namespace std;
const int N=1000007;
vector<int> to[N];
int d1[N],d2[N];
void dfs(int o,int fa,int* d){
	for(auto i:to[o]) if(i!=fa) d[i]=d[o]+1,dfs(i,o,d);
}
int main(){
	freopen(name".in","r",stdin);
	freopen(name".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t-->0){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) to[i].clear();
		for(int i=1,u,v;i<n;i++) cin>>u>>v,to[u].push_back(v),to[v].push_back(u);
		if(k==n){cout<<"0\n";continue;}
		if(c==13||c==14){
			cout<<max(((n+1)/2+5-k)/4,1)<<'\n';
			continue;
		}
		if(k==2){
			int ans=0x3f3f3f3f;
			for(int i=1;i<=n;i++) for(int j=i+1;j<i;j++){
				d1[i]=d2[j]=0;
				dfs(i,0,d1),dfs(j,0,d2);
				int hbw=0;
				for(int k=1;k<=n;k++) hbw=max(hbw,min(d1[k],d2[k]));
				ans=min(ans,hbw);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
} 
/*
CSP-S rp += inf
NOIP rp += inf
Never give up any problems as I have lost NOIP2025.
See ancestors on Halloween at /discuss/898803.
//froepen
//ferepen
//retrun
//freopen("hbw.ans","r",stdout);
dsa
dsasa
dsasasa
dsasasasa
dsasasasasa
*/
