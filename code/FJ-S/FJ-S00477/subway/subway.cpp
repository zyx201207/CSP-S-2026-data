#include<bits/stdc++.h>
using namespace std;
const int N=303; 
#define ll long long
int c,n,m,d,q,k,a,ti,x,y;
ll f[N][N],w[N],t[N][N],ans;
vector<int>ls[N];
/*
0 2 5 20 2

4 1 9 2 5

3 1 5 2 7 4 6

3 2 3 3 4 5 7

1 3
1 2

*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>ti;
			ls[a].push_back(i);
			t[i][a]=ti;
		} 
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int k=1;k<=m;k++){
		if(ls[a].size()<2)continue;
		for(int i:ls[k]){
			for(int j:ls[k]){
				if(i==j)continue;
				for(int i1=1;i1<=n;i1++)
					f[i][j]=min(f[i][j],f[i][i1]+f[])
			}
		}
	}
	for(int i=1;i<=n;i++,cout<<'\n'){
		for(int j=1;j<=n;j++)cout<<f[i][j]<<' ';
	}
	while(q--){
		cin>>x>>y;
		ans=0x3f3f3f3f;
		for(int lx:ls[x]){
			for(int ly:ls[y]){
				cout<<'('<<lx<<' '<<ly<<")\n";
				ans=min(ans,t[lx][x]+f[lx][ly]+t[ly][y]);
			}
		}
		cout<<w[x]+ans+w[y]<<'\n';
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
