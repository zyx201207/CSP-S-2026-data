#include<bits/stdc++.h>
using namespace std;
long a[1001];
long b[1001];
int sum=0;
int main()
{
	//n能量水晶数量，m最多可进行的操作次数 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];  
	}
	freopen("crystal.in","n","stdin");
	freopen("crystal.out","m","stdou") ;
	return 0;
}
/*
for(int j=0;j<=b[j];j++)
{
	if(b[j]==a[i])
	{
		sum+=2;
	}
}
cout<<sum;
*/
