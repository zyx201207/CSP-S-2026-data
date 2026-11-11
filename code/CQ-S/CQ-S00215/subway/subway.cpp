#include<bits/stdc++.h>
using namespace std;
int csbh,n,m,d,q,kdt[500010],tdt[500010],bh[500010],bj[500010];//³ö¿Úµ½Õ¾Ìü   
int ans,qd,zd;
struct info{
	int y,sj;
};
vector<info>a[500010];
void dfs(int x,int s){
	if(x==zd){
		ans=min(ans,s);
		return ;
	}
	if(s>ans||s>bj[x])return ;
	bj[x]=s;
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i].y,z=a[x][i].sj;
		dfs(y,s+z);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>csbh>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>kdt[i];
	}
	for(int i=1,len;i<=n;i++){
		cin>>len;
		for(int j=1;j<=len;j++){
			cin>>bh[j]>>tdt[j];
		}
		for(int j=1;j<=len;j++){
			for(int k=1;k<=len;k++){
				if(j==k)continue;
				a[bh[j]].push_back({bh[k],tdt[j]+tdt[k]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		memset(bj,0x3f,sizeof(bj));
		cin>>qd>>zd;
		ans=1e9;
		dfs(qd,0);
		cout<<ans+kdt[qd]+kdt[zd]<<endl;
	}
	return 0;
}
