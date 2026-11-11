#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10]={0};
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int bj=0;
		for(int j=1;j<=i;j++)
		{
			if(a[i]==a[j] && i!=j)
			{
				bj=1;
			}
			if(bj==0)
			{
				sum++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<n<<" ";
	} 
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
