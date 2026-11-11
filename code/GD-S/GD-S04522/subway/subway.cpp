#include<bits/stdc++.h>
using namespace std;
struct node{
	pair<int,int> a1;
};//first: the station, second: the time
short c;
int n,m,d,q,x,y;
int w[125253],k[503];//time
node a[503][500003];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int p=1;p<=n;p++){
		cin>>k[p];
		for(int i=1;;i++){
			for(int j=1;j<=k[p];j++){
				cin>>a[i][j].a1.first>>a[i][j].a1.second;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x>>y;
	}
	for(int i=1;i<=n;i++){
		cout<<w[i]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
