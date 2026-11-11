#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<ctime>
#include<cstring>
#include<cstdio> 
#define int long long
#define INF 100000000000000
using namespace std; 
inline int read(){
	int sumer=0;
	int p=1;
	char t;
	do{
		t=getchar();
		if(t=='-') p=-1;
		if(t<='9'&&t>='0') sumer=sumer*10+t-'0';
	}while(t=='-'||(t<='9'&&t>='0'));
	return sumer*p;
}
int c,n,m,d,r,k,a,t,B[501][501];
vector<int>V[510000];
vector<int>W[510000];
int ZT[510000];
void Floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) B[i][j]=0;
			for(int k=1;k<=n;k++){
				B[i][j]=min(B[i][j],B[i][k]+B[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();r=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)B[i][j]=INF;
	}
	for(int i=1;i<=m;i++) ZT[i]=read();
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			a=read();
			t=read();
			V[a].push_back(i);
			W[a].push_back(t);
		}
	}
	for(int i=1;i<=m;i++){
		int siz=V[i].size();
		for(int j=0;j<siz;j++){
			for(int z=0;z<j;z++){
				//cout<<i<<' '<<V[i][j]<<' '<<V[i][z]<<' '<<W[i][j]<<' '<<W[i][z]<<' '<<'\n';
				B[V[i][j]][V[i][z]]=min(B[V[i][j]][V[i][z]],W[i][j]+W[i][z]);
				B[V[i][z]][V[i][j]]=min(B[V[i][z]][V[i][j]],W[i][j]+W[i][z]);
			}
		} 	
	}
	Floyd(); 
	for(int i=1;i<=r;i++){
		int x,y,sumn=INF;
		cin>>x>>y;
		for(int j=0;j<V[x].size();j++){
			for(int z=0;z<V[y].size();z++){
				//if(V[y][z]==V[x][j]) sumn=0;
				sumn=min(sumn,B[V[x][j]][V[y][z]]+W[x][j]+W[y][z]);
			}
		}
		cout<<sumn+ZT[x]+ZT[y]<<'\n';
	}
	return 0;
}
/*
我已经不知道怎么优化了
求求神机发力 
*/
