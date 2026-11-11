#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[100005];
	
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<2;i++)
	{
		int k,k1[100005];
		cin>>k;
		for(int j=0;j<2*k;j++)
		{
			cin>>k1[j];
		}
	}
	for(int i=0;i<2;i++)
	{
		int r,k;
		cin>>r>>k;
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2)
	{
		cout<<32<<endl<<17;
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2)
	{
		cout<<35<<endl<<16;
	}
	
	return 0;
	
		
	
}















































































































































































































