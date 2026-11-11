#include<bits/stdc++.h>
using namespace std;
/*bool hui(char a[100005],int n)
{
	for(int i=n-1,j=0;i>-1,j<n;i--,j++)
	{
		if(a[i]==a[j])
		return 0;
	}
	return 1;
}*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[100005],sum;
	char c[100005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	sum=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]!=sum)
		break;
		else
		{
		cout<<0;
		return 0;	
		}
	}
	return 0;
}
