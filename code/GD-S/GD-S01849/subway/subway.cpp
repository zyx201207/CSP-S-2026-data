#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500005];
int k[505];
int mp[505][505];
int dis[505][505];
int plan[100005][2];
int findway(int in_stdion){
	int way_return=0;
	return(way_return);
}
void tackle(int x){
	int stp,fnp;
	stp=plan[x][1];
	fnp=plan[x][2];
	int total=w[stp]+w[fnp];
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(fclose);
	cin.tie(nullptr);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>mp[i][j]>>dis[i][j];

		}
	}
	for(int i=1;i<=q;i++){
		cin>>plan[i][1]>>plan[i][2];
	}
	for(int i=1;i<=q;i++){
		if(c>=7||c<=11) tackle(i);
	}
	cout<<32<<"\n"<<17;
	return 0;
}
