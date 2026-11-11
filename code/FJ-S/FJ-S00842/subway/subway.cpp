#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=505;
const int M=5e5+5;
const int inf=1e18;
int c,n,m,d,q,A,T;
int w[M],k[N],edge[N][N];
vector<pair<int,int> > e[M];
int read(){
	int s=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s;
}
void write(int x){
	if(x<10){
		putchar(x+48);
		return;
	}
	write(x/10);
	putchar(x%10+48);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(register int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			edge[i][j]=inf;
	for(register int i=1;i<=m;i++)
		w[i]=read();
	for(register int i=1;i<=n;i++){
		k[i]=read();
		for(register int j=1;j<=k[i];j++){
			A=read(),T=read();
			e[A].push_back({i,T});
		}
	}
	for(register int i=1;i<=m;i++){
		for(auto u : e[i]){
			for(auto v : e[i]){
				if(u.first==v.first)
					continue;
				edge[u.first][v.first]=edge[v.first][u.first]=u.second+v.second;
			}
		}
	}
	for(register int tmp=1;tmp<=n;tmp++)
		for(register int i=1;i<=n;i++)
			for(register int j=1;j<=n;j++){
				if(i!=tmp&&tmp!=j) 
					if(edge[i][tmp]+edge[tmp][j]<edge[i][j])
						edge[i][j]=edge[i][tmp]+edge[tmp][j];
			}	
	int x,y,ans;
	for(register int i=1;i<=q;i++){
		ans=inf;
		x=read(),y=read();
		for(auto u : e[x]){
			for(auto v : e[y]){
				if(u.first==v.first)
					ans=min(ans,u.second+v.second);
				else
					ans=min(ans,u.second+v.second+edge[u.first][v.first]);
			}
		}
		write(ans+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7

*/
