#include<bits/stdc++.h>
using namespace std;
string b,c;
long long n,a,l=0,f=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>b;
		l+=a;
		for(int j=1;j<=a;j++)
		{
			c+=b;
		}
	}
	
	
    for(int i=0;i<l/2;i++)
    {
    	if(c[i]!=c[l-1-i])
    	{
    		f++;
		}
	}
	cout<<f;
}
