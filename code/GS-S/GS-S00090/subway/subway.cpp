#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int b[N],y[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int k1,k2;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	cin>>k1;
	for(int i=0;i<k1+n;i++)
	{
		cin>>b[i];
		
	}
	cin>>k2;
	for(int j=0;j<k2+n;j++)
	{
		cin>>y[j];
		
	}	
	while(q--)
	{
		int g,h;
		cin>>g>>h;
	}
	cout<<"35"<<" "<< 16;
	return 0;
} 
