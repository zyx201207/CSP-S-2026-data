#include<iostream>
using namespace std;
int main()
{

	int n,m;
	int sum1=0; 
	int sum2=500001;
	cin >> n >> m;
	char cry[n+2];
	char cha[n]; 
	for(int i=1;i<=n;i++)
	{
		cin >> cry[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(cry[i]>cry[i+1])
		{
			cha[i]=cry[i]-cry[i+1];
		}
		else if(cry[i]<cry[i+1])
		{
			cha[i]=cry[i+1]-cry[i];
		}
		else if(cry[i]==cry[i+1])
		{
			cha[i]=0;
		}
	}
	
	for(int i=1;i<=n;i++) 
	{
		if(cha[i]<=sum2)
		{
			sum2=cha[i];
		}	
	}
	 
	while(m>0)
	{
		for(int i=1;i<=n;i++)
		{
			if(cha[i]=sum2&&m-cha[i]>=0) 
			{
				m=m-cha[i]; 
				cha[i]=0;
				sum1++;
			}
			sum2++;
		}
	}
	cout<<sum1<<endl;
	return 0;
}
