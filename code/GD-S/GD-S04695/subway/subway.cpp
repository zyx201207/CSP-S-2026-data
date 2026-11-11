#include<bits/stdc++.h>
using namespace std;
const int N=50001;
int n,m;
struct point{
	int to;
	int time;
};
int w[N];
vector<point> p[N];
void bfs(int s,int e){
	queue<int> q;
	int time[N];
	bool vis[N];
	q.push(s);
	vis[s]=true;
	memset(vis,0,sizeof(vis));
	memset(time,0x3f,sizeof(time));
	time[s]=0;
	while(!q.empty()){
		int Q=q.front();
		q.pop();
		for(int i=0;i<p[Q].size();i++){
			int too=p[Q][i].to;
			int ti=p[Q][i].time;
			if(vis[too]!=1||time[too]>time[Q]+ti){
				q.push(too);
				time[too]=min(time[too],time[Q]+ti);
				vis[too]=1;
			}
		}
	}
	cout<<w[s]+w[e]+time[e]<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[N],t[N];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j]; 
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(a[l]!=a[j]){
					p[a[j]].push_back((point){a[l],t[j]+t[l]});
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		bfs(s,e);
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
