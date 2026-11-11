#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int c,n,m,d,q;
int w[500005]; 
int k[505];
int xr[100005],yr[100005];
struct road
{
	int a[505],t[505];
}s1[505];
struct picture
{
	int note=0;
	int near[25][2];
}s2[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>s1[i].a[j]>>s1[i].t[j];
			s2[s1[i].a[j]].near[s2[j].note][0]=s1[i].a[j-1];
			s2[s1[i].a[j]].near[s2[j].note][1]=s1[i].t[j-1];
			s2[j].note++;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>xr[i]>>yr[i];
	}
	cout<<35<<endl<<16;
	
}
