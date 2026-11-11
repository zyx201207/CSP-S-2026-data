#include<bits/stdc++.h>
using namespace std;
long long int n=0,m=0;
long long int arr[500005]={0};
long long int shou[500005]={0};
long long int arr1[500005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>shou[i];
	}
	for(int i=1;i<=n;i++)
	{
		int a=1;
		for(int j1=1;j1<=n;j1++)
		{
			arr[j1]=0;
		}
		for(int j=i;j<=n;j++)
		{
			
			int o=0;
			for(int k=1;k<=a;k++)
			{
				if(shou[j]==arr[k])
				{
					for(int k1=k;k1<=a;k1++)
					{
						arr[k1]=0;
						a--;
					}
					arr[a]=shou[j];
					a++;
					o=1;
					break;
				}
				
			}
			if(o==0)
			{
				arr[a]=shou[j];
				a++;
			}
		}
		for(int j=1;j<=n;j++)
		{
			arr1[arr[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<arr1[i]<<' ';
	}
	return 0;
}
