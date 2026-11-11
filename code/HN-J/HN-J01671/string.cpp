#include <bits/stdc++.h>
using namespace std;
string a[10000000],d[10000000];
main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string c;
	int n,b,sum=0,cnt=0,l=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>b>>c;
		for(int j=1;j<=b;j++)
		{
			sum+=1;
			a[sum]=c;
		}
	}
	for(int i=sum;i>=sum/2;i--)
	{
		l++;
		d[l]=a[i];
	}
	for(int i=1;i<=sum/2;i++)
	{
		if(a[i]!=d[i])
		    cnt++;
	}
	cout<<cnt;
	return 0;
}
//不休独舞芙宁娜 

//天才少年米提亚 
