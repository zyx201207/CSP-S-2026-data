#include<bits/stdc++.h>
#define int long long
using namespace std;
int INF;
int c,n,m,d,q; 
int e[501][501];
map<int,int> mp[501];
vector<int> z[500005];
int w[500005];
int in[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q; 
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	memset(e,0x3f,sizeof(e));
	INF=e[1][1];
	for(int i = 1;i<=n;i++) {
		cin>>in[i];
		for(int j = 1;j<=in[i];j++){
			int a1,t1;
			cin>>a1>>t1;
			mp[i][a1]=t1; 
			z[a1].push_back(i);
		}
	}
	for(int i = 1;i<=n;i++){
		e[i][i]=0;
	}
	for(int k = 1;k<=m;k++){
		for(int i = 0;i<z[k].size();i++){
			for(int j = 0;j<z[k].size();j++){
				int vai=z[k][i],vaj=z[k][j];
				if(vai==vaj) continue;
				e[vai][vaj]=e[vaj][vai]=min(e[vaj][vai],mp[vai][k]+mp[vaj][k]);
			} 
		}
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(e[i][k]+e[k][j]<e[i][j]){
					e[i][j]=e[i][k]+e[k][j];
				} 
			} 
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e17;
		for(int i:z[x]){
			for(int j:z[y]){
				ans=min(ans,e[i][j]+mp[i][x]+mp[j][y]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
/*
n,d都很小，求总步行时间 
考虑把地铁线路看成点，跑最短路 ，floyd
17:22写完， 大样例跑0.7还有救吗
也就是说，kskbl,我有200pts了（雾 

这是暴力还是正解啊 
*/
