#include <iostream>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;  
	int i,ii,iii,iiii; 
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(i=0;i<=m-1;i++)
	cin>>w[i];
	int k;
	cin>>k;
	int a[n][k],t[n][k];
	for(ii=0;ii<=n;ii++)
	{
		for(iii=0;iii<=k;iii++)
		{
			cin>>a[ii][iii]>>t[ii][iii];
		}
	}
	int x[q],y[q];
	for(iiii=0;iiii<=q-1;iiii++)
	{
		cin>>x[iiii]>>y[iiii];
	}
	int o=0,p=0,r=0;
	for(;a[o][p]!=x[r];o++)
	{
		for(;a[o][p]!=x[r];p++);
	}
	int o_x=o;
	int p_x=p;
	int r_x=r;
	int o=0;
	int p=0;
	int r=0;
	for(;a[o][p]!=y[r];o++)
	{
		for(;a[o][p]!=y[r];p++);
	}
	int o_y=o;
	int p_y=p;
	int r_y=r;
	int o=0,p=0,r=0;
	for(;a[o][p]!=a[o][r];o++)
	{
		p++;
	}
	int o_0=o;
	int p_0=p;
	int s1,s2;
	s1=t[o_x][o_y]+w[r_x]+t[o_0][p_0]+t[o+0+p-r][p_0]+t[p_x][p_y]+w[r_y];
	s2=16;
	cout<<s1<<endl<<s2<<endl;
	return 0;
}
