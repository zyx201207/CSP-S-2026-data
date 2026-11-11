#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
long long n, m;
int a[N]={0};
int x=1;
int mn =N;
int f(int temp)
{
	for (int x = 1; x<=n; x+=temp)
	{
		if ((x+x*x)/2 >= (2*m) && (2*m) >= (x*x-x)/2) 
		{
			return x;
		}
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long temp=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout <<f(a[2]-a[1])%N-1;
	return 0;
 } 
