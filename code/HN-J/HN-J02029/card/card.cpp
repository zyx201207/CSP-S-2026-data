#include<bits/stdc++.h>
using namespace std;
int a[25];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,sum=0,num=0,sb=0;
	cin>>n>>m;
	sum==a[25];
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i];
		num+=a[i];
		sb+=a[i+1];
	 
		while(i++)
		{
			if(a[i]>a[i+1]||a[i]<a[i+1])
			{
				cout<<a[i]<<" "<<a[i+1];
				num++;
				sb++;
			} 
			if(a[i]==a[i+1])
			{
				cout<<a[i+1];
				sb++;
			}
		}
	}
	cout<<num<<sb;
	return 0;
}

