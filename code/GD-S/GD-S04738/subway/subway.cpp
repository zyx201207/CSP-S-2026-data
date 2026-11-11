#include<bits/stdc++.h>
using namespace std;
int c,n,t,d,m,k[500005],v[500005],a[5005][5005],ti[5005][5005],ans=1e9,l,r,spt[1001][501];
bool vi[5005][5005];
int point[1001][21],tail[21];
struct str{
	int x,time;
}q[500001];
int tai,h=1;
void bfs(int st,int en){
	int ans;
	q[++tai].x=st;
	while(h<=tai){
		if(q[h].x==en){
			cout<<q[h].time<<'\n';
			break;
		}
		for(int i=1;i<=tail[q[h].x];i++){
			q[++tai].x=point[q[h].x][i],q[tai].time=q[h].time+spt[q[h].x][point[q[h].x][i]];
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>ti[i][j];
			vi[i][a[i][j]]=1;
		}
	}
	if(c>=7&&c<=11){
		
		for(int i=1;i<=21;i++){
			tail[i]=0;
		}
		for(int i=1;i<=m;i++){
			if(k[i]==1){
				continue;
			}
			else{
				point[a[i][1]][++tail[a[i][1]]]=a[2],point[a[2]][++tail[a[i][2]]]=a[1];
				spt[a[i][1]][a[i][2]]=ti[i][1],spt[a[i][2]][a[i][1]]=ti[i][2];
			}
		}
		for(int i=1;i<=t;i++){
			cin>>l>>r;
			bfs(l,r);
		}
	}
	return 0;
} 
