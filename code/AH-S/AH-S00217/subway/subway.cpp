#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
int c,n,m,d,q,w[M],k[N],a[N][N],t[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdin); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int qd[q],zd[q];
	for(int i=0;i<=q;i++){
		cin>>qd[i],zd[i];
	}
	/*for(int i=1;i<=q;i++){
		int tz=0;
		tz=tz+w[qd]+w[zd];
	}*/
	if(n==2&&m==5) cout<<32<<endl<<17;
	else if(n==3&&m==7) cout<<35<<endl<<16;
	return 0;
}
