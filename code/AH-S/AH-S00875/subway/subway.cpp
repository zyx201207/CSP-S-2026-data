#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=1005;
vector<int> x[M],v[M];
int a[N],w[N],k[N];
int g[M][M],dd[M][M],pd[M][M];
int c,n,m,d,q;
void dijst(int x){
	dd[x][x]=0;
   for(int i=1;i<=m;i++){
   int minn=1e18,st=0;
   for(int j=1;j<=m;j++){
	   if(!pd[x][j]&&dd[x][j]<=minn) minn=dd[x][j],st=j;
	  }	
	 pd[x][st]=true;
	 if(st==0) return ;
	 for(int j=1;j<=m;j++) dd[x][j]=min(dd[x][j],dd[x][st]+g[st][j]);
}}
signed main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
cin>>c;
if(c>=0&&c<=11){
memset(g,0x3f,sizeof(g));
memset(dd,0x3f,sizeof(dd));
cin>>n>>m>>d>>q;
for(int i=1;i<=m;i++) cin>>w[i];
for(int ik=1;ik<=n;ik++){
	cin>>k[ik];
	for(int j=1;j<=k[ik];j++)
	{
		int aa,tt;
		cin>>aa>>tt;
		x[ik].push_back(aa);
		v[ik].push_back(tt);
	}
	for(int i=0;i<k[ik];i++)
	  for(int j=0;j<k[ik];j++){
		// cout<<x[ik][i]<<' '<<x[ik][j]<<'\n';
		  g[x[ik][i]][x[ik][j]]=min(g[x[ik][i]][x[ik][j]],v[ik][i]+v[ik][j]);
		  g[x[ik][j]][x[ik][i]]=min(g[x[ik][j]][x[ik][i]],v[ik][i]+v[ik][j]);
	  }
  }
  /*for(int i=1;i<=m;i++){
    for(int j=1;j<=m;j++) cout<<(g[i][j]==4557430888798830399?-1:g[i][j])<<' ';
    cout<<'\n';
}*/
for(int i=1;i<=m;i++) {g[i][i]=0;}

    for(int i=1;i<=m;i++) dijst(i);
  /*    for(int i=1;i<=m;i++){
    for(int j=1;j<=m;j++) cout<<(dd[i][j]==4557430888798830399?-1:dd[i][j])<<' ';
    cout<<'\n';
}*/
while(q--){
	   int s,t;
	   cin>>s>>t;
	   cout<<dd[s][t]+w[s]+w[t]<<'\n';
	}
}
return 0;
}/*1 2 5 20 15
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5 1 1 2 2 3 3 4 4 5 5
*/
