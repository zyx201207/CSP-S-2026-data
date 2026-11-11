#include<bits/stdc++.h>
using namespace std;
int w[505050];
long long dis[505][505];
struct node{
	int zhandian,step;
}a[505050];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j].zhandian>>a[j].step;
		}
		for(int j=1;j<=k;j++){
			for(int p=j+1;p<=2*k;p++){
				dis[a[j].zhandian][a[p].zhandian]=w[a[j].zhandian]+w[a[p].zhandian]+a[j].step+a[p].step;
				dis[a[p].zhandian][a[j].zhandian]=w[a[j].zhandian]+w[a[p].zhandian]+a[j].step+a[p].step;
			}
		}
	}
	//for(int i=1;i<=m;i++){
		//for(int j=1;j<=m;j++){
			//cout<<dis[i][j]<<" ";
		//}
		//cout<<"\n";
	//}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(k==i||k==j) continue;
				if(dis[i][k]+dis[k][j]-2*w[k]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j]-2*w[k];
				}
			}
		}
	}
	//for(int i=1;i<=m;i++){
		//for(int j=1;j<=m;j++){
			//cout<<dis[i][j]<<" ";
		//}
		//cout<<"\n";
	//}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<dis[l][r]<<"\n";
	}
	return 0;
}
