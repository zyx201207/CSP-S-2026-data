#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,z=0,x=0;
	cin>>a>>b;
	vector<int> c,d;
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<m;i++)
	{
	 if(c[i]+2*n-1==c[i+3])
	 {
	 z++;
	 }
	}
	cout<<z<<" ";
	int q,p;
	cin>>q>>p;
	for(int i=0;i<q;i++)
	{
		cin>>d[i];
	}
	for(int i=0;i<q;i++)
	{
	 if(d[i]+2*p-1==d[i+3])
	 {
	 x++;
	 }
	}
	cout<<x;
	
	fclose(stdin);
	fclose(stdout);
}
