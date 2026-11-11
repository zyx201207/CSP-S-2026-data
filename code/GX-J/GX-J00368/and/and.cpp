#include<bits/stdc++.h>
using namespace std;

int n,m;
long long num[201000];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>num[i];
	
	sort(num,num+n);
	
	long long max=num[n-1];
	for(int i=n-2;m-1>0;i--,m--)
		max = max & num[i];
	
	cout<<max;
	
	return 0;
}


