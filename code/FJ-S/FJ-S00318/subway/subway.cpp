#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;vector<int>w;vector<map<int,long long>>t;vector<vector<int>>v;
vector<vector<long long>>dis;
inline long long rea(){
	long long x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}c=getchar();
	}while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}return x*f;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	c=rea(),n=rea(),m=rea(),d=rea(),q=rea();
	t.resize(m),w.resize(m);v.resize(n);
	dis.resize(m+1,vector<long long>(m+1,0x3f3f3f3f3f3f3f3f));
	for(int i=0;i<m;i++){w[i]=rea();dis[i][i]=0;}
	for(int i=0;i<n;i++){
		int kkk=rea();v[i].resize(kkk);
		for(int j=0;j<kkk;j++){
			v[i][j]=rea()-1;
			int x=rea();
			t[v[i][j]][i]=x;
			for(int k=0;k<=j;k++){
				dis[v[i][k]][v[i][j]]=dis[v[i][j]][v[i][k]]=min(dis[v[i][j]][v[i][k]],((t[v[i][k]][i])+(t[v[i][j]][i])));
			}
		}
	}
	for(int k=0;k<m;k++)
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int k=0;k<q;k++){
		int x=rea()-1,y=rea()-1;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	}
	return 0;
}
