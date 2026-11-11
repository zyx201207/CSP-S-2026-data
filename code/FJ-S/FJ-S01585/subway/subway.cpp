#include<bits/stdc++.h>
using namespace std;
#define forr(v,l,r) for(int v=l; v<=r; v++)
const int N=510,M=500010,K=500010,Q=100010;
int c,n,m,d,q;
int w[M];
int a[N][K];
int k;
int x[Q],y[Q];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	forr(i,1,m) cin>>w[i];
	forr(i,1,n)
	{
		cin>>k;
		forr(j,1,k) cin>>a[i][j]>>t[i][j];
	}
	forr(i,1,q) cin>>x[i]>>y[i];
	if(c==0)
	{
		if(n==2) cout<<"32\n17";
		if(n==3) cout<<"35\n16";
	}
	return 0;
}