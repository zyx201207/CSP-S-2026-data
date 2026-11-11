#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,mint,w[100005],a[10005][10005],t[10005][10005],f[10005][10005],bj[100005];
void dfs(int li,int b,int e,int time){
	if(b==e){
		mint=min(mint,time+w[e]);
		return ;
	}
	if(time>=mint) return ;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		if(f[b][j]==1&&bj[j]==0&&t[i][j]!=0){
			bj[j]=1;
			dfs(i,j,e,time+t[i][b]+t[i][j]);
			bj[j]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int z=1;z<=c;z++){
		memset(w,0,sizeof(w));
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		memset(f,0,sizeof(f));
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			int k=0;
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>a[i][j]>>t[i][j];
				if(j==2){
					f[a[i][j]][a[i][j-1]]=1;
					f[a[i][j-1]][a[i][j]]=1;
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x=0,y=0;
			cin>>x>>y;
			memset(bj,0,sizeof(bj));
			mint=99999999;
			for(int j=1;j<=n;j++){
				if(t[j][x]!=0) dfs(j,x,y,w[x]+t[j][x]);
			}
			cout<<mint<<endl;
		}
	
	} 
	
	return 0;
}
