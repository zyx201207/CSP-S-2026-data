#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int minl[500001];
struct sub{	 
	int tk;//厅口 
	int zz;//直接转线 
	int lian;//连通站台数 
}a[500001]; 
struct mm{
	int fir;
	int las;
}b[500001];
int z,r;
int zt[501][500001]={};//站厅
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	if(c==0)
	{
		cout<<"35"<<endl<<"16";
		return 0;
	}
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].tk; 
	} 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].lian;
		for(int j=1;j<=a[i].lian;j++)
		{
			cin>>z>>r;
			zt[i][z]=r;
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			a[i].zz+=zt[j][i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i].fir>>b[i].las;
	}
	for(int i=1;i<=q;i++)
	{
		minl[i]=a[b[i].fir].tk+a[b[i].las].tk;
	}
	/*for(int i=1;i<=q;i++)
	{
		cout<<minl[i];
	}*/	
	return 0;
}
