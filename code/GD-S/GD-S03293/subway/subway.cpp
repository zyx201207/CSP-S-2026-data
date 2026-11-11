#include<bits/stdc++.h>
using namespace std;
const int mx1=5*1e5+5,qx1=1e5+5;
int c,n,m,d,q,k[505],a[mx1],b[505][mx1],e[505][mx1],x[qx1],y[qx1];
long long zdl[505][505];
int main(){
	preopen("poker.in","r",stdin);
	preopen("poker.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(j==i)
				zdl[i][j]=0;
			else
				zdl[i][j]=0x3f3f3f3f;
	for(int i=0;i<m;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
			cin>>b[i][j]>>e[i][j];
	}
	for(int i=0;i<q;i++)
		cin>>x[i]>>y[i];
	return 0;
}
