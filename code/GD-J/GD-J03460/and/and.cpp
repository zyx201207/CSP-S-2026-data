#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;	
	cin>>n;
	int x;
	cin>>x;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	sort(a,a+n+1,cmp);
	long long y=a[0];
	for(int i=1;i<x;i++)
    {
    	y=y&a[i];
	}
	cout<<y;
	return 0;
}
