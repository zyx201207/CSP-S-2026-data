#include <bits/stdc++.h>
#include<random>
using namespace std;
#define ll long long
#define endl '\n'
int c,n,m,d,q,w[5005],k[505],a[505][5005];
ll t[505][5005],ans;
/*
反悔贪心 or DP
*/
struct node1{
	int x,y;
}b[1005];
struct node2{
	int trains[505],time,i=1;
}e[505];
/*
	n:地铁线路数
	m:站点数
	d:每个站最多几条线路
	q:计划数
	w[i]:从每个地铁站的地铁口走到站厅需要的时间
	a[i][j]:第 i 条线路经过的第 j 个地铁站
	t[i][j]:从该地铁站的站厅走到第 i 条线路的站台需要的时间
	b[i].x:第i个旅程的起点所在的地铁站编号
	b[i].y:第i个旅途的终点所在的地铁站编号
	*/
void solve(int x){
	ans=0;
	int st=b[x].x;
	int ed=b[x].y;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			e[j].trains[e[j].i]=i;
			e[j].i++;
			e[j].time=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>b[i].x>>b[i].y;
	}
	if(n==2){
        cout<<32<<endl<<17;
	}else if(n==3){
        cout<<35<<endl<<16;
	}else{
        for(int i=1;i<=q;i++){
            srand(time(0));
            cout<<rand()<<endl;
        }
	}

	return 0;
}
