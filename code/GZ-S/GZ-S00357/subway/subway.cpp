//GZ-S00357 贵阳实验二中 刘子墨
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],x,y,k;
int s[505][505];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			s[i][j]=y;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		
	}
	return 0;
} 
