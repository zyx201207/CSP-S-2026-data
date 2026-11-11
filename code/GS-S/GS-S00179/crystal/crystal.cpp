#include<iostream>
using  namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,t,t1,sum;
	cin>>n>>m;
	int s[n];
	for(int i;i<n;i++)
	{
		cin>>s[i];
		}	
	for(int g;g<n;g++)
	{
		if(s[g]<s[g+1])
		{
			t=s[g];
			s[g]=s[g+1];
			s[g+1]=t;		
		}
	}	
	for(int j;j<n;j++)
	{
		if(s[j]==s[j+1])
		{
			sum+=1;
			t1=s[j];
		}
	}
	while(m>0)
	{
		for(int k;k<n;k++)
		{
			if(t1-s[k]<m)
			{
				s[k]=t1;
				m=m-(t1-s[k]);
				sum+=1;
			}
			else
			continue;
		}
	}
	cout<<sum;
	return 0; 
}
