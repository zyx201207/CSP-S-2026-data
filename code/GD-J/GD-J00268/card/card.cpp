#include<bits/stdc++.h>
using namespace std;
int n,a[500005],c[500005],d[300005],m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	d[a[i]]++;
	}
	for(int i=1;i<=n;i++)
    {
    	d[a[i-1]]--;
    	for(int j=1;j<=m;j++)
    	    if(d[i]%2>0)c[i]++;
	}
	for(int j=1;j<=m;j++)
	    cout<<c[j]<<" ";
	return 0;
} 
