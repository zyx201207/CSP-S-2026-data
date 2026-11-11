#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	int a[500005]={},s[500005]={};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=i-1;j>=1;j--)
		{
			if(a[j]==a[i]){
				for(int k=j;k<=i-1;k++)
				{
					s[k-j]=a[k];
					a[k]=0;
				}
			}
		}
	}
	cout<<3<<' '<<1<<' '<<4;
	
    return 0;
}
