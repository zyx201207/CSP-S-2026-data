#include<bits/stdc++.h>
using namespace std;
int u,n,m,d,q,w[500005],ans,qd,zd,id[500005];
struct node{
	int l,va;
};
vector<node> s[500005];
vector<int> a[500005];
node c[500005];
void dfs(int n,int sum2,int parent){
	if(n==zd){
		ans=max(ans,sum2);
		return;
	}
	for(int i=0;i<int(a[n].size());i++){
		int son=a[n][i];
		if(son!=parent){
			dfs(son,sum2+s[son][0].va,n);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>u>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		memset(c,0,sizeof(c));
		memset(id,0,sizeof(id));
		for(int j=1;j<=p;j++){
			int zt,t;
			cin>>zt>>t;
			c[j].l=i;
			c[j].va=t;
			id[j]=zt;
		}
		for(int j=1;j<p;j++){
			for(int k=j+1;k<=p;k++){
				a[id[j]].push_back(id[k]);
				a[id[j]].push_back(id[k]);
			}
		}
		for(int j=1;j<=p;j++){
			s[id[j]].push_back(c[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<int(a[i].size());j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=1;i<=q;i++){
		cin>>qd>>zd;
		int sum1=0;
		sum1=w[qd]+w[zd];
		dfs(qd,s[qd][0].va,qd);
		cout<<sum1+ans<<"\n";
	}
	return 0;
}
