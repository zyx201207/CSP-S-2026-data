#include<bits/stdc++.h>
using namespace std;

long long n,sum;
long long m[250005];
char c[250005];
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>m[i]>>c[i];
	int i=1,j=n;
	while(i<j)
	{	
		if(c[i]==c[j])
		{
			
			if(m[i]==m[j])
			{
				i++;j--;
			}
			else if(m[i]>m[j])
			{
				m[i]-=m[j];
				j--;
			}
			else
			{
				m[j]-=m[i];
				i++;
			}
		}
		else
		{
			sum+=min(m[i],m[j]);
			
			if(m[i]==m[j])
			{
				i++;j--;
			}
			else if(m[i]>m[j])
			{
				m[i]-=m[j];
				j--;
				
			}
			else
			{
				m[j]-=m[i];
				i++;		
			}
			
		}
	}
	cout<<sum;
}
