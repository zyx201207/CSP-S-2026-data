#include <bits/stdc++.h> 
using namespace std;
#define for(a,b,c) for(int a=b;a<=c;a++)
int c,n,m,d,q,w[508],k[508],xian[500008];
vector<int> h[500008],a[500008],t[500008],jd[500008];//图，a，t，交点所包含的线路数 
//int find(int x,int y,int xa) {
//	if(xian[x]==0) return 0;
//	for(i,0,jd[y].size()-1) {
//		if(jd[y][i]==xian[x]) return xian[x];
//	int remn=INT_MAX,reid=0,re;
//	for(i,0,jd[x].size()-1) 
//		for(j,0,jd[y].size()-1) {
//			if(jd[x][i]==jd[y][j]) {
//				int o=jd[x][i];
//				if(o==xian[x]) re=t[o][x]+t[o][y];
//			}
//		}
//	xian[x]=
//	return xian[x];
//} 
int spfa(int st,int en) {
	queue<int> q;
	q.push(st);
	int z[m+5],ppo=0;
	for(i,1,m) z[i]=INT_MAX;
	z[st]=0;
	bool b[500008]={};
	xian[st]=0;
	while(q.size())	{
		int p=q.front();
		for(i,0,h[p].size()-1) {
			if(!b[h[p][i]]) {
				int o=xian[p],lu;
				if(o) lu=z[p]+t[o][p]+t[o][i];
				else lu=z[p]-t[o][p]+t[o][i];
				xian[i]=xian[p];
				z[i]=min(z[i],lu);
				q.push(i);
				b[h[p][i]]=1;
			}
		}
		q.pop();
	}
	return z[en]+w[st]+w[en];
}
signed main() {
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数
	for(i,1,m) cin>>w[i];
	
	for(i,1,n) {
		a[i].push_back(0);
		t[i].push_back(0);
		cin>>k[i];
		for(j,1,k[i]) {
			int A,T;
			cin>>A>>T;
			a[i].push_back(A);
			t[i].push_back(T);
			jd[A].push_back(i);
		}
	}
	for(i,1,n) {
		for(j,1,k[i]-1) {
			h[a[i][j]].push_back(a[i][j+1]);
		}
	}
	while(q--) {
		int l,r;
		cout<<spfa(l,r)<<endl;
	}
	return 0;
}
/*
2 5 2 0 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
