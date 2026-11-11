#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int c,n,m,d,q;
int w[MAXN];
vector<int> a[MAXN],t[MAXN];
int k[500];
struct node{
	int a;
	int t;
}T[MAXN];
int tim[MAXN];


int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//c,n,m,d,q，分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	for(int i=0;i<m;i++){
		cin>>w[i];//依次表示从每个地铁站的地铁口走到站厅需要的时间。
	}
	for(int i=0;i<n;i++){
		cin>> k[i];
		for(int j=0;j<k[i];j++){
			int x;
			cin>>x;
			
			int y;
			cin>>y;
		}// a 表示第 i 条线路经过的第 j 个地铁站，t  表示从该地铁站的站厅走到第 i 条线路的站台需要的时间。
	}
	return 0;	
}

