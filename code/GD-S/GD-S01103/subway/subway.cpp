#include<bits/stdc++.h>
using namespace std;
//bool ST;
int id,n,m,d,q;
long long Dis[505][505],dis[500005],ans[100005],w[500005];
int vis[500005];
vector<pair<int,int> > vLine[505],vStation[500005];
struct node{
	int x,y;
}Ask[100005];
int read(){
	char op=getchar();
	while(!(op>='0'&&op<='9')) op=getchar();
	int num=0;
	while(op>='0'&&op<='9') num*=10,num+=(op-'0'),op=getchar();
	return num;
}
void write(long long ans){
	if(ans>9) write(ans/10);
	putchar('0'+(ans%10));
}
//bool ED;
signed main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&id,&n,&m,&d,&q),memset(Dis,63,sizeof(Dis));
	for(int i=1;i<=n;i++) Dis[i][i]=0;
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1,len;i<=n;i++){
		len=read();
		for(int j=1,x,t;j<=len;j++) x=read(),t=read(),vLine[i].push_back({x,t}),vStation[x].push_back({i,t}); 
	}
	for(int i=1;i<=m;i++)
		for(pair<int,int> a:vStation[i])
			for(pair<int,int> b:vStation[i]){
				Dis[a.first][b.first]=min(Dis[a.first][b.first],(long long)(a.second)+(long long)(b.second));
				Dis[b.first][a.first]=min(Dis[b.first][a.first],(long long)(a.second)+(long long)(b.second));
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(Dis[i][k]==Dis[0][0]) continue;
			for(int j=1;j<=n;j++)
				Dis[i][j]=min(Dis[i][j],Dis[i][k]+Dis[k][j]);
		}
	for(int i=1;i<=q;i++) Ask[i].x=read(),Ask[i].y=read(),ans[i]=LLONG_MAX;
	for(int i=1;i<=n;i++){
		memset(dis,63,sizeof(dis));
		for(int j=1;j<=m;j++) vis[j]=0;
		for(int j=1;j<=n;j++)
			for(pair<int,int> w:vLine[j])
				dis[w.first]=min(dis[w.first],Dis[i][j]+w.second);
		for(pair<int,int> w:vLine[i]) vis[w.first]=w.second;
		for(int T=1;T<=q;T++)
			if(vis[Ask[T].x])
				ans[T]=min(ans[T],dis[Ask[T].y]+vis[Ask[T].x]);
	}
	for(int i=1;i<=q;i++) write(ans[i]+w[Ask[i].x]+w[Ask[i].y]),putchar('\n');
//	cerr<<"Static Memory: "<<((int)((&ED)-(&ST)))*1.0/1024/1024<<".MB\n";
	return 0;
}
/*
g++ subway.cpp -o cmd.exe -O2 -std=c++14 -static -Wall -Wextra
*/
