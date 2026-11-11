#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	long long num=0,m=0;
	string b,c[200000000000005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i]>>b;
	    for(int j=1;j<=a[i];j++)
	    {
	        c[num]=b;
			num++;
	    }
    }
    for(int i=0;i<=num/2;i++)
    {
    	if(c[i]!=c[n-i])
    	    m++;
	}
	cout<<m;
	return 0;
}
