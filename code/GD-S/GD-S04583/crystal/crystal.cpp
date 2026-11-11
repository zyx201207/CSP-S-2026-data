#include <iostream>
#include <algorithm>
using namespace std;

long long n,m;
int a[5000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int sum=0,temp=0,same=0;
	cin >>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[j]==a[j+1])
			{
				temp=a[j];
				same++;
			}
			else if(a[j]!=a[j+1])
			{
				temp=a[j+1];
				for (int k=1;k<=n;k++)
				{
					if((temp-a[k])+(temp-a[k+1])==m)
					{
						a[k]=temp;
						a[k+1]=temp;
						/*cout <<temp<<" ";*/
						for (int z=1;z<=n;z++)
						{
							if(a[z]==temp) sum++;
						}
					}
				}
				
			}
		}
		if ((temp-a[i])+(temp-a[i+1])==m)
		{
			a[i]=temp;
			a[i+1]=temp;
			for (int i=1;i<=n;i++)
			{
				if(a[i]==temp) sum++;
			}
			break;
			
		}
		
		
		
	}
	cout <<sum;
	return 0;
}
