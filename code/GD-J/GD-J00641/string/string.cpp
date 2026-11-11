#include<bits./stdc++.h>
using namespace std;
int n,d,s;
int a[100000000];
string b,c;
int main()
{
    freopen("string.in","r",stdin); 
    freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		d+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			c+=b[i];
		}
	}
	if(d%2==0)
	{
		for(int i=1;i<=d/2;i++)
		{
			if(c[d/2-i]!=c[d/2+i-1])
			{
				s+=1;
			}

		}
	}	
	
	else
	{
		for(int i=1;i<=d/2;i++)
		{
			if(c[d/2-i]!=c[d/2+i])
			{
				s+=1;
			}
		}
	}
	cout<<s;
}
