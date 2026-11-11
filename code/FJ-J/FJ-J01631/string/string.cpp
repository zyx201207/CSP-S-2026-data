#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0,cnt,sum=0;
	cin>>n;
	char a[200005],b;
	for(int i=0;i<n;i++)
	{
		cin>>cnt>>b;
		for(int j=k;j<k+cnt;j++)
		{
			a[j]=b;
		}
		k+=cnt;
	}
	int kk=k/2;
	for(int i=0;i<kk;i++)
	{
		if(a[i]!=a[kk-i])
		sum++;
	}
	cout<<sum<<endl;
 }
