#include<bits/stdc++.h>
using namespace std;
#define int long long
//n地铁几条线，m地铁多少站，d最多几线过，q出行计划数
int c,n,m,d,q;
//w地铁口到站厅，a[i][j]第i条线路经过第j个地铁站,t[i][j]从j站的站厅到i线时长
int w[13000],a[50][13000],t[50][13000];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	map<int,set<int> >mp;//线对应的站
	map<int,set<int> >mp2;//站有多少线
	map<pair<int,int>,set<int> >mp3;//a站的b线可以去c
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[i][(j+1)/2];//a[i][j]第i条线路经过第j个地铁站
			cin>>t[i][a[i][(j+1)/2]];
			mp[i].insert(a[i][(j+1)/2]);//线对应的站
			mp2[a[i][(j+1)/2]].insert(i);//站有哪些线
		}
		for(auto it:mp[i]){
			for(auto it2:mp[i]){
				if(it==it2) continue;
				mp3[{it,i}].insert(it2);
				mp3[{it2,i}].insert(it);
			}
		}
	}
	while(q--){
		int ans=1e18;
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(mp[i].count(x) && mp[i].count(y)){
				ans=min(ans,w[x]+t[i][x]+t[i][y]+w[y]);
			}
		}for(int i=1;i<=m;i++){
			for(auto it:mp2[i]){//第i站有哪些线（it）
				for(auto it2:mp2[i]){//第i站有哪些线（it2）
					if(mp3[{i,it}].count(x) && mp3[{i,it2}].count(y)){
						ans=min(ans,w[x]+t[it][x]+t[it][i]+t[it2][i]+t[it2][y]+w[y]);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
