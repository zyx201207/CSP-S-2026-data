#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
bool keyi=true;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long chazhi[n];
	for(int i=1;i<=n-1;i++)
	{
		for(int j=n;j>=2;j--)
		{
			if(j>i&&keyi==true)
			{
				memset(chazhi,0,sizeof(chazhi));
				for(int ii=1;ii<=j-1;ii++)
				{
					chazhi[ii]=a[j]-a[ii];
				}
				int sum=0;
				for(int ii=1;ii<=j-1;ii++)
				{
					sum+=chazhi[ii];
				}
				if(sum<=m)
				{
					cout<<j-i+1<<endl;
					
					keyi=false;
					break;
				}
				else
				{
					continue;
				}
			}
			else if(j==i&&keyi==true)
			{
				cout<<1;
				
				break;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
