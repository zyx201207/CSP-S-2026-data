#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll line,tost;
};
ll c,n,m,d,q,w[500005],ans,t[505][500005],ma[500005],be,en;
vector<node>step[500005];
void dfs(ll lie,ll poin,ll num){
	if(poin==en){
		ans=min(ans,num+t[lie][en]+w[be]+w[en]);
		return;
	} 
	for(int i=0;i<step[poin].size();i++){
		ll li=step[poin][i].line,to=step[poin][i].tost;
		if(ma[to]==1) continue;
		if(li!=lie) {
			ma[to]=1;
			ll num1=num+t[li][poin];
			if(poin!=be) num1+=t[lie][poin];
			dfs(li,to,num1);
			ma[to]=0;
		}else{
			ma[to]=1;
			dfs(li,to,num);
			ma[to]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k,u,v,dan=0;
		cin>>k;
		while(k--){
			cin>>u>>v;
			t[i][u]=v;
			if(dan==0){
				dan=u;
				continue;
			}
			dan=u;
			step[dan].push_back({i,u});
		}
	}
	while(q--){
		cin>>be>>en;
		memset(ma,0,sizeof ma);
		ans=INT_MAX;
		dfs(0,be,0);
		cout<<ans<<endl;
	}
	return 0;
}
