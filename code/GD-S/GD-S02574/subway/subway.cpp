#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[20005];
struct fraaa{
	bool yn;
	int lenth;
};
bool have[505][20005];
fraaa vis[20005];
struct subway_road{
	int a,c,road;
};
subway_road test_cin[20005];
vector<subway_road> a[505];
struct farrr{
	int a,lenth,road;
};
void bfs(int strat,int finish,int road){
	queue<farrr> q;
	q.push({strat,0,road});
	while(q.size()>0){
		int y=q.front().a;
		vis[y].yn=1;
		vis[y].lenth=q.front().lenth;
		for(int i=0;i<a[y].size();i++){
			if(have[q.front().road][a[y][i].a]){
				if(!vis[a[y][i].a].yn||vis[a[y][i].a].lenth>q.front().lenth){
					q.push({a[y][i].a,q.front().lenth,q.front().road});
				}
			}
			else{
				int tt=0;;
				for(int j=0;j<a[a[y][i].a].size();j++){
					if(a[a[y][i].a][j].a==a[y][i].a){
						tt=a[a[y][i].a][j].c;
					}
				} 
				if(!vis[a[y][i].a].yn||vis[a[y][i].a].lenth>(q.front().lenth+a[y][i].c+tt)){
					q.push({a[y][i].a,q.front().lenth+a[y][i].c+tt,a[y][i].road});
				}
			}
		}
		q.pop();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<n;i++){
		memset(test_cin,0,sizeof(test_cin));
		int ki;
		cin>>ki;
		for(int j=0;j<ki;j++){
			scanf("%d%d",&test_cin[j].a,&test_cin[j].c);
			have[i+1][test_cin[j].a]=1;
		}
		for(int j=0;j<ki;j++){
			for(int k=j+1;k<ki;k++){
				a[test_cin[j].a].push_back({test_cin[k].a,test_cin[k].c,i+1});
				a[test_cin[k].a].push_back({test_cin[j].a,test_cin[j].c,i+1});
			} 
		}
	}
	for(int i=0;i<q;i++){
		int str,fin;
		cin>>str>>fin;
		int min_lenth=999999999;
		for(int j=0;j<a[str].size();j++){
			memset(vis,0,sizeof(vis));
			bfs(str,fin,a[str][j].road);
			min_lenth=min(vis[fin].lenth,min_lenth);
		}
		cout<<(w[str-1]+w[fin-1]+min_lenth)<<"\n";
	}
	return 0;
}
