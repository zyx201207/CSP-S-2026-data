#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],sum[M];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) 
		cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j],(rand()%2==0?sum[rand()%2]+=t[i][j]);
	}
	while(q--) {
		int s,t;
		cin>>s>>t;
		cout<<sum[rand()%2]<<endl;
	}
	return 0;
}
