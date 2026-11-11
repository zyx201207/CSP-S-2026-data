#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[500005],summ,pp,w[500005],b[500005];
int a[10005][10005],t[10005][10005];
bool f[10005][10005];
struct add{
	int xx,yy;
}r[500005];
void dfs(int xxx,int ans,int sum){
	if(xxx==pp){
		summ=max(sum,summ);
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			int g=xxx;
			if(b[xxx]==b[a[i][j]]&&f[i][j]==0){
				xxx=a[i][j];
				f[i][j]=1;
				sum+=t[i][j]+ans;
				dfs(xxx,t[i][j],sum);
				xxx=g;
				f[i][j]=0;
				sum-=t[i][j]-ans;
			}
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
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			b[a[i][j]]=i;
			f[i][j]=0;
		}
	}
	for(int i=1;i<=q;i++){
		summ=0;
		cin>>r[i].xx>>r[i].yy;
		pp=r[i].yy;
		for(int j=1;j<=n;j++){
			dfs(r[i].xx,t[j][r[i].xx],t[j][r[i].xx]);
			f[i][j]=0;
			
		}
		cout<<summ+w[r[i].xx]+w[r[i].yy]<<endl;
	}
	return 0;
}


