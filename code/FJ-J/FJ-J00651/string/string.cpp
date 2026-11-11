#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,sum=0,d=0,d1=0,di=0,ii,n2;
	char a;
	string s;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		d+=x;
		cin>>a;
	    for(int j=1;j<=x;j++)
	    {
	    	s+=a;
		}
		 
	}
    for(int i=0;i<=d/2;i++)
	{
		if(d%2==1&&i==d/2)
		{
			
		}
		else if(d!=0)
		{
			if(s[i]!=s[d-i-1])
			{
				sum++;
				s[d-i-1]=s[i];
			}
		}
	}	
	cout<<sum;
	return 0;
}


