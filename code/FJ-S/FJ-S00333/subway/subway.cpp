#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int w[MAXN];
vector<long long>st[502][2];//0为被哪些线穿过，1为对该线路站厅-站台步行时间 
vector<long long>u[502][2];//0为与哪条路相连，1为对该线路步行时间;
vector<long long>e;
struct node{
	long long z,l;
};
int bfs(int x,int y){
	bool d[502];
	memset(d,0,sizeof(d));
	queue<node>q;
	for(int i=0;i<st[x][0].size();i++){
		q.push({st[x][0][i],st[x][1][i]});
	}
	long long mins=LONG_LONG_MAX;
	while(!q.empty()){
		bool fd=0;
		int f=q.front().z;
		for(int i=0;i<e.size();i++){
			if(e[i]==f){
				fd=1;
				break;
			}
		}
		if(fd){
			int ind;
			for(int i=0;i<st[y][0].size();i++){
				if(st[y][0][i]==f){
					ind=i;
					break;
				}
			}
			mins=min(mins,q.front().l+st[y][1][ind]);
			q.pop();
			continue;
		}
		//搜索所有与当前线路相连的线路 
		for(int i=0;i<u[f][0].size();i++){
			if(!d[u[f][0][i]]){
				q.push({u[f][0][i],q.front().l+u[f][1][i]});
				d[u[f][0][i]]=1;
			}
		}
		q.pop();
	}
	return mins;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	long long ans;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	int x1,s1,l1;
	for(int i=1;i<=n;i++){
		cin >> x1;
		for(int j=1;j<=x1;j++){
			cin >> s1 >> l1;
			st[s1][0].push_back(i);
			st[s1][1].push_back(l1);
		}
	}
	//生成图
	for(int i=1;i<=m;i++){
		for(int j=0;j<st[i][0].size()-1;j++){
			for(int k=j+1;k<st[i][0].size();k++){
				u[st[i][0][j]][0].push_back(st[i][0][k]);
				u[st[i][0][j]][1].push_back(st[i][1][j]+st[i][1][k]);
				u[st[i][0][k]][0].push_back(st[i][0][j]);
				u[st[i][0][k]][1].push_back(st[i][1][j]+st[i][1][k]);
			}
		}
	}
	
	int x,y;
	for(int i=1;i<=q;i++){
		ans=0;
		cin >> x >> y;
		ans+=w[x]+w[y];
		e.clear();
		for(int i=0;i<st[y][0].size();i++){
			e.push_back(st[y][0][i]);
		}
		ans+=bfs(x,y);
		cout << ans << endl;
	}
	return 0;
}
