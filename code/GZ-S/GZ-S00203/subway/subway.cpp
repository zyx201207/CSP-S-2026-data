//GZ-S00203 北京师范大学贵阳附属中学 周一宸  
#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5+23;

int c,n,m,d,q,k;

struct way{
	int pos[N][2],pos_i = 1;
	
	void push(int di,int pay){
		pos[pos_i][0] = di;
		pos[pos_i++][1] = pay;
	}
}road[503];

struct tai{
	int time; 
	int lu[23][2],road_i = 1;
	
	void push(int wa,int pay){
		lu[road_i][0] = wa;
		lu[road_i++][1] = pay;
	}
}vid[N];

void bfs2(int x,int y){
	int vis[1000003];
	queue<int> bfs;
	int dtai;
	int ntai,nl;
	int ans =0;
	while(!bfs.empty()){
		dtai = bfs.front();
		if(dtai = y){
			bfs.pop();
			continue;
		}
		for(int i=1;i<vid[dtai].road_i;i++){
			nl = vid[dtai].lu[i][0];
			for(int j=1;j<road[nl].pos_i;j++){
				if(road[nl].pos[j][0]==dtai){
					continue;
				}
				if(road[nl].pos[j][1]+vid[dtai].lu[i][1]<vis[dtai]){
					vis[dtai] = road[nl].pos[j][1]+vid[dtai].lu[i][1];
					bfs.push(road[nl].pos[j][0]);
				}
			}
		}
		bfs.pop();
	}
	cout<<vis[y]+vid[x].time+vid[y].time<<endl;
}

int a,t;
int main () {
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>vid[i].time;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j =1;j<=k;j++){
			cin>>a>>t;
			road[i].push(a,t);
			vid[a].push(i,t);
		}
	}
	int x1,y1,x,y;
	for(int x=1;x<=q;x++){
		cin>>x1>>y1;
		bfs2(x1,y1);
		x =x1,
		y = y1;
		int vis[1000003];
		queue<int> bfs;
		int dtai;
		int ntai,nl;
		int ans =0;
		bfs.push(x);
		while(!bfs.empty()){
			dtai = bfs.front();
			if(dtai = y){
				bfs.pop();
				continue;
			}
			for(int i=1;i<vid[dtai].road_i;i++){
				nl = vid[dtai].lu[i][0];
				for(int j=1;j<road[nl].pos_i;j++){
					if(road[nl].pos[j][0]==dtai){
						continue;
					}
					if(road[nl].pos[j][1]+vid[dtai].lu[i][1]<vis[dtai]){
						vis[dtai] = road[nl].pos[j][1]+vid[dtai].lu[i][1];
						bfs.push(road[nl].pos[j][0]);
					}
				}
			}
			bfs.pop();
		}
		cout<<vis[y]+vid[x].time+vid[y].time<<endl;

	}
	
	return 0 ;
}

