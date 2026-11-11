#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
struct node1{
	int x,y,z;
};
vector<node> t[100005];
int w[100005],l,vis[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c>=7&&c<=11){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			if(k==2){
				for(int i=1;i<=k;i++){
					int x,y;
					cin>>x>>y;
					t[++l].push_back({x,y});
				}
			}
		}
		for(int i=1;i<=q;i++){
			int k,d;
			cin>>k>>d;
			queue<node1> q;
			q.push({0,w[k],0});
			while(!q.empty()){
				node1 s=q.front();
				q.pop();
				if(s.x==d){
					cout<<s.y<<endl;
					break;
				}
				for(int j=1;j<=l;j++){
					if(t[j][0].x==s.x){
						q.push({t[j][1].x,s.y+t[j][1].y+t[s.x][s.z].y,1});
					}else if(t[j][1].x==s.x){
						q.push({t[j][0].x,s.y+t[j][0].y+t[s.x][s.z].y,0});
					}
				}
			}
		}
	}
	return 0;
}
