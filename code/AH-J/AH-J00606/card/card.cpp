#include<bits/stdc++.h>
using namespace std;
string c;
long long n,s=0,a[10000001],b[10000001],k=1,g,m=c.size(),w;

char z[10000001],f;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	char x,y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>x;
		b[x]+=a[i];
	}
	for(int i='a';i<='z';i++) 
	{
		if(b[i]>m)
		{
		    m=b[i];
		} 
		s+=b[i];
	}
	cout<<s-m;
	return 0; 
}
