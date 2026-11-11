#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	int n,m;
	cin>>n>>m;
	int sum=0,sum1=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=m;i++)
	{	
		a[i]++;
		if(sum1==0&&a[i]!=a[i++])
		{
			return 0;
		}
		else if(sum1==0&&a[i]==a[i++])
		{
			sum++;
			break;
		}
		if(a[i]==a[i++])
		{
			sum++;
			sum1--;
		}
	}
	cout<<sum;
	return 0;
} 
