#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
//地铁口->站厅1->站台1->站厅2->站台2->……->站台x->站厅x->地铁口 
const int maxm=5e5+5;
const int maxn=505; 
int w[maxm];//地铁口<->站厅 
int k[maxn];//经过站点数
vector<pair<int,int>> t[maxm];//站台<->站台 
vector<pair<int,int> dist[maxm];//存站厅->站厅边权邻接表 ,相当于站厅->站台->站厅的值 
int c,n,m,d,q;//测试点编号，地铁线路数，地铁站数，每点最大边数， 测试点数 
int main(){
	#ifdef fre
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	#endif
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int p=0;
		for(int j=1;j<=k[i];j++){
			int a;cin>>a;
			int tb;cin>>tb;
			t[a].push({i,tb});//a->i号线的时间为tb 
			
		} 
		
	}
	for(int i=1;i<=n;i++); 
} 
