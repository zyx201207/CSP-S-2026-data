#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,c=0,d[200005],n=2000000000000000000000000000000005;
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
	    cin>>d[i];
	    if (d[i]<=n)n=d[i];
	}
	if(a==b)c=n;
	cout<<c;
	return 0;
}
