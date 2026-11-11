#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,l,sum=0;
    char p,a[6000001];
    int num=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>l>>p;
		for(int j=1;j<=l;j++)
		{
			sum++;
			a[sum]=p;
		}
	}
	num=0;
	for(int i=1;i<=sum/2;i++)
	{
		if(a[i]!=a[sum-i])num++;
	}
	cout<<num;
    return 0;
}

