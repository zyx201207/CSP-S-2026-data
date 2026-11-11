#include<bits/stdc++.h>
using namespace std;
int e,n,m,d,q,w[500005],ans=10000000;
struct BIAN{
	int a[50005],t[50005],k;
}bian[505];
bool vis[500005];
vector<int> c[500005];
void dfs(int p,int y,int cnt,int o){
	if(p==y){
		ans=min(ans,cnt);
		return ;
	}
//	cout<<endl<<1<<' ';
	int l=c[p].size(),ll;
	for(int i=0;i<l;i++){
		ll=bian[c[p][i]].k;
//		cout<<c[p][i]<<':';
		for(int j=1;j<=ll;j++){
//			cout<<bian[c[p][i]].a[j]<<' ';
			if(!vis[bian[c[p][i]].a[j]]&&i!=o){
				vis[bian[c[p][i]].a[j]]=true;
				dfs(bian[c[p][i]].a[j],y,cnt+bian[c[p][i]].t[j],o);
				vis[bian[c[p][i]].a[j]]=false;
			}
		}
	}
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>e>>n>>m>>d>>q;
	long long b[m][m];
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>bian[i].k;
		for(int j=1;j<=bian[i].k;j++){
			cin>>bian[i].a[j]>>bian[i].t[j];
			c[bian[i].a[j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<bian[i].k;
		for(int j=1;j<=bian[i].k;j++){
			cout<<' '<<bian[i].a[j]<<' '<<bian[i].t[j];
		}
		cout<<endl;
	}
	int u,v;
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		vis[u]=true;
		ans=10000000;
		dfs(u,v,w[u]+w[v],0);
		cout<<ans<<endl;
		for(int i=1;i<=m;i++){
			vis[i]=false;
		}
	}
	return 0;
}
