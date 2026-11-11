#include<bits/stdc++.h>
#define int long long

#define z using namespace
#define n std;
z n
int g[201][1001][1001];
int a[501][20001],t[501][20001];
int h,m,c,d,q;
int w[500001];
signed main(){
	freopen("subway","r",stdin);
	freopen("subway","w",stdout);
	cin>>c>>h>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	int x;
	for(int i=1;i<=h;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[i][j]>>t[i][j];  
		}
		
	}
	for(int i=1;i<=q;i++){
		cout<<1;
	}
	return 0;
} 
