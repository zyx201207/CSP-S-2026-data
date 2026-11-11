#include<bits/stdc++.h>
using namespace std;
int sum=0,n,num=0,tum=0,t=0;
long long sz[190000000];
char zm[190000000],s[190000000];
int main()
{
//	froepen("string","r",stdin);
//	froepen("string","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>sz[i]>>zm[i];
		num+=sz[i];
		if(zm[i]==zm[i-1])	sum++; 
		for(int j=sz[i-1]+1;j<=sz[i-1]+sz[i];j++)
		{
			s[j]=zm[i];
		}	
	}
	for(int j=1;j<=num;j++)
		{
			cout<<s[j];
		}	
	if(sum==n-1)
	{
		cout<<'0';
		return 0;
	} 
	if(num%2==0)
	{
		for(int i=num/2;i>=1;i--)
		{
			for(int j=num/2+1;j<=num;j++)
			{
				if(s[i]==s[j])
				{
					break;
					cout<<s[i]<<' '<<s[j]<<endl;
				} 
				else
				{ 
					tum++;
					cout<<s[i]<<' '<<s[j]<<endl;
					break;
				}
			}
		}
		cout<<tum;
		return 0;
	}
	if(num%2!=0)
	{
		for(int i=(num-1)/2;i>=1;i--)
		{
			for(int j=(num-1)/2+1;j<=num;j++)
			{
				if(s[j]==s[i]) 
				{
					break;
				}
				else
				{
					t++;
					break;
				}
			}
		}
		cout<<t;
		return 0;
	 }

	
	return 0;
}
