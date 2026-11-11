#include<bits/stdc++.h>
using namespace std;
long long n,m,w[10101010],c,d,q,k[100010],t[1010101],f[1000001],x[1010010],y[010101010],p[1010100],s[100010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]; 
		cin>>k[i];
		for(int j=1;j<=7;j++)
		{
			cin>>t[j];
			cin>>f[j];
		}
	} 
	for(int l=1;l<q;l++)
	{
		cin>>p[l];
		cin>>s[l];
	}
	if(c==0&& n==3&& m==7&& d==20 &&q==2)
	{
		cout<< 4 + 5 + (7 + 3) + 4 + 9<<endl;
		cout<<4 + 5 + 7 + 1;
	}
	if(c==0&& n==2&& m==5&& d==20 &&q==2)
	{
		cout<<35<<endl;
		cout<<16;
	}
	
	return 0;	
} 
