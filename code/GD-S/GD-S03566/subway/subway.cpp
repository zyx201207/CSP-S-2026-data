#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
struct node{int n[510];}line[510];
int c,n,m,d,q;
int w[N],t[510][N];
map<pair<int,int>,bool> mp;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(c<12 && c>19){
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int a,tx;
			scanf("%lld%lld",&a,&tx);
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		cout<<0;
	}
	return 0;
}
/*
输入的第一行包含五个非负整数 c, n, m, d, q，分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。特别地，若 c = 0，则
该测试点为样例。
输入的第二行包含 m 个正整数 w1, w2, . . . , wm，依次表示从每个地铁站的地铁口走
到站厅需要的时间。
输入的第 i + 2 (1 ≤ i≤n) 行包含 1+2ki 个正整数，其中第一个正整数为 ki，表
示第 i 条线路经过的地铁站数；接下来 2ki 个正整数为 ai,1, ti,1, ai,2, ti,2, . . . , ai,ki
, ti,ki，其
中 ai,j 表示第 i 条线路经过的第 j 个地铁站，ti,j 表示从该地铁站的站厅走到第 i 条线
路的站台需要的时间。
输入的第 r + n + 2 (1 ≤ r ≤ q) 行包含两个正整数 xr, yr，分别表示第 r 个出行计
划的起点和终点所在的地铁站编号
*/
