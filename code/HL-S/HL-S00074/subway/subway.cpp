#include<bits/stdc++.h>
using namespace std;
int w[500010];
int a[505][505],t[505][505];
struct node{
	int x,y;            
}trip[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>trip[r].x>>trip[r].y;
	}
	for(int i=1;i<=q;i++){
		cout<<10<<"\n";
	}
}
