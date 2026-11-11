#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b;
	string c,d;
	string result=0;
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		result[0]=1;
		long long m=(c[0]-'0')*10+(c[1]-'0');
		long long n=(d[0]-'0')*10+(d[1]-'0');
		if(m==n)
		{
			result[1]=1;
		
			if(c[2]=='F')
			{
				if(d[2]=='D')
				{
					result[2]=1;
					result[3]=1;	
				}
				else
				{
					result[2]=0;
					result[3]=0;
		        }
			}
			else if(c[2]=='D')
			{
				if(d[2]=='F')
				{
					result[2]=1;
					result[3]=1;	
				}
				else
				{
					result[2]=0;
					result[3]=0;
				}
			}
			else if(c[2]=='A')
			{
				if(d[2]=='B'||d[2]=='C')
				{
					result[2]=1;
					if(d[2]=='B')
						result[3]=1;
					else
						result[3]=0;
				}
				else
				{
					result[2]=0;
					result[3]=0;
				}
			
			}
			else if(c[2]=='B')
			{
				if(d[2]=='A'||d[2]=='C')
				{
					result[2]=1;
					result[3]=1;
				}
				else
				{
					result[2]=0;
					result[3]=0;
				}
			}
			else if(c[2]=='C')
			{
				if(d[2]=='B'||d[2]=='A')
				{
					result[2]=1;
					if(d[2]=='B')
						result[3]=1;
					else
						result[3]=0;
				}
				else
				{
					result[2]=0;
					result[3]=0;
				}
			
			}
		}
	    else
		{
			result[1]=0;
			result[2]=0;
			result[3]=0;
		}
	}

	else
	{
		result[0]=0;
		result[1]=0;
		result[2]=0;
		result[3]=0;
	}
	cout<<result;
	return 0;
}
