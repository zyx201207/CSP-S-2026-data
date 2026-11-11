#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[500005];
struct node{
	int to[25];
	int ti[25];
	int g;
}arr[500005];
bool f[500005];
int s[500005];
int bfs(int s,int e){
	queue<int> q;
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			arr[i].g++;
			cin>>arr[i].to[arr[i].g]>>arr[i].ti[arr[i].g];
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		cout<<abs(y-x);
	}
	return 0;
}
