#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y;
int w[1000000];
int a[10000][10000],t[10000][10000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x>>y;		
		int ans=0;
	}
	return 0;
}
