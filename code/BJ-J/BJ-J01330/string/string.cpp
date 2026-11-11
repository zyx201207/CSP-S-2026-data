#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a="";
    int n,x,cnt=0;
    char y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
		cin>>x>>y;
		for(int j=0;j<x;j++)
		{
			a+=y;
		}
	}
	int i=0,j=n-1;
	while(i<=j)
	{
		if(a[i]!=a[j])
		{
			cnt++;
		}
		i++;
		j--;
	}
	cout<<cnt;
    return 0;
}
