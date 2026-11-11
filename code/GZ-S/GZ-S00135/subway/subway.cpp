//GZ-S00135 胡睿晨 北京师范大学贵阳附属中学
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500010],k[510];
struct node{
	long long id,t;
}a[510][500010];
long long x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j].id>>a[i][j].t;
		}
	}
	while(q--){
		cin>>x>>y;
	}
	return 0;
}
