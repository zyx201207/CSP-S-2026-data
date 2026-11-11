#include<bits/stdc++.h>
using namespace std;int c,n,m,d,q;
int ans=0;
vector <int> e[500005],ee[505][505];
int w[500005];
int k[505];
int a[505][500005],t[505][500005];
int f[505];
int x,y;

//int dd(int x,int y,int an){
//	for(auto v:e[x]){
//		if(f[v]==1) an=min(an,t[v][x]+t[v][y]);
//		else for(auto g:e[y]){
//			for(auto d:ee[v][g]) if(d!=x){
//				an=min(an,dd(d,y,an));
//			}
//		}
//	}
//	return an;
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	for(int i=1;m>=i;i++){
		cin>>w[i];
	}
	for(int i=1;n>=i;i++){
		cin>>k[i];
		for(int j=1;k[i]>=j;j++){
			cin>>a[i][j]>>t[i][j];
			t[i][a[i][j]]=t[i][j];
			t[i][j]=0;
			for(auto v:e[a[i][j]]){
				ee[v][i].push_back(a[i][j]);
				ee[i][v].push_back(a[i][j]);
			}
			e[a[i][j]].push_back(i);
		}
	}
	
	while(q--){
		cin>>x>>y;
		ans+=w[x]+w[y];
		for(auto v:e[y]){
			f[v]=1;
		}
//		ans+=dd(x,y,0);
		cout<<ans;
	}
	return 0;
} 
