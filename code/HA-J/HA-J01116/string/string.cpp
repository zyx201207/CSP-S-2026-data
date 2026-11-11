#include <bits/stdc++.h>
using namespace std;
char brr[105];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n,arr[100005],sum=0,num=0;
	cin>>n;
	int a;
	cin>>a>>brr[0];
	arr[0]=a;
	sum=a;
	for(int i=1;i<n;i++)
	{
		int j;
		cin>>j;
		arr[i]=j;
		cin>>brr[i];
		if(brr[i]==brr[0])
		sum+=arr[i];
		else
		num+=arr[i];
	}
	if(num==0)
	cout<<num;
	else{
	if(sum>=num)
	cout<<num;
	else
	cout<<sum;
	}
	return 0;
};
