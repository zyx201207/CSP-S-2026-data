#include<bits/stdc++.h>
using namespace std;
int w[500001],c,n,m,d,q,s;
vector<int> a1[501],t1[501],a2[500001],t2[500001];
bool st[500001];
void dfs(int zt,int xl,int y,int h,bool hu) {
	if(zt == y) {
		h += t1[xl][zt];
		h += w[zt];
		s = min(s,h);
		return;
	}
	if(h > s) return;
	if(xl == -1) for(int i : a2[zt]) dfs(zt,a2[zt][i],y,h+t2[zt][i],1);
	st[zt] = true;
	for(int i = 0;i < a1[xl].size();i++) if(!st[a1[xl][i]]) dfs(a1[xl][i],xl,y,h,0);
	if(!hu) {
		hu = true;
		for(int i = 0;i < a2[zt].size();i++) {
			if(a2[zt][i] == xl) {
				dfs(zt,-1,y,h+t2[zt][i],hu);
				break;
			}
		}
	}
	st[zt] = false;
	return;
}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int x,y;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++) scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++) {
		scanf("%d",&x);
		for(int j = 1;j <= x;j++) {
			scanf("%d",&y);
			a1[i].push_back(y);
			a2[y].push_back(i);
			scanf("%d",&y);
			t1[i].push_back(y);
			t2[y].push_back(i);
		}
	}
	while(q--) {
		scanf("%d%d",&x,&y);
		s = 1e9;
		dfs(x,-1,y,w[x],0);
		printf("%d\n",&s);
	}
	return 0;
}
