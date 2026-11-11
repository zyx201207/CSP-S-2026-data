#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5,N=505;
int ID;
int n,m,d,q;
ll need[M],ff[M][2];
ll dist[5002][5002];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>ID>>n>>m>>d>>q;
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++) cin>>need[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			ll l,r;
			cin>>l>>r;
			ff[i][0]=l;ff[i][1]=r;
			for(int j=1;j<i;j++){
				dist[l][ff[j][0]]=dist[ff[j][0]][l]=r+ff[j][1];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int l=1;l<=m;l++){
				dist[i][j]=min(dist[i][j],dist[i][l]+dist[l][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]+need[x]+need[y]<<"\n";
	}
	return 0;
}

