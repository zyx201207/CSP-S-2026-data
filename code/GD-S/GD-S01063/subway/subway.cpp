#include<bits/stdc++.h>
#define N 600505
#define M 505
#define ll long long
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
int n,m,k,jk,sum,num,cnt,tot;
ll dis[N],wis[N],f[M][M],ans;
vector<pair<int,int> > G[N];

void read(int &x){
	x=0;int ff=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ff=(ch=='-'?-1:ff),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=ff;return;
}

void write(ll x){
	if(x<0){x=-x;putchar('-');}
	if(x>=10) write(x/10);
	putchar('0'+(x%10));return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);//WYW
	read(jk);read(n),read(m),read(k),read(jk);
	for(int i=1,x;i<=m;i++) read(x),wis[i]=x;
	for(int i=1,z;i<=n;i++){read(z);
		for(int j=1,x,t;j<=z;j++){
			read(x),read(t);
			G[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=i==j?0:1e15;
	for(int i=1;i<=m;i++){
		for(int x=0;x<(int)G[i].size();x++){
			for(int y=x+1;y<(int)G[i].size();y++){
				pair<int,int> A=G[i][x],B=G[i][y];
				f[B.first][A.first]=f[A.first][B.first]=min(f[A.first][B.first],(ll)A.second+B.second);
			}
		}
	}
	for(int p=1;p<=n;p++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) f[i][j]=min(f[i][p]+f[p][j],f[i][j]);
	while(jk--){int x,y;
		read(x),read(y);ans=1e15;
		for(int i=0;i<(int)G[x].size();i++){
			for(int j=0;j<(int)G[y].size();j++){
				pair<int,int> A=G[x][i],B=G[y][j];
				ans=min(ans,A.second+f[A.first][B.first]+B.second);
			}
		}
		wh(ans+wis[x]+wis[y]);
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
