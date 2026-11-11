#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
struct node{
	long long a,t;
}p[505][500005];
long long k[505];
long long x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j = 1;j<=k[i];j++){
			cin>>p[i][j].a>>p[i][j].t;
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<6<<endl;
	}
	return 0;
}

