#include<bits/stdc++.h>
using namespace std;
long long w,n,mid,q,e=1;
string z;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w>>c;
		for(int j=1;j<=w;j++)
		{
			z[e]=c;
			e++;
		}
	}
	e--;
	int mid=e;
	w=mid;
	if(mid%2==0)mid=int(mid/2)+1;
	else mid=mid/2;
	for(int i=1;i<=mid;i++)
	{
		if(z[i]!=z[e+1-i])
		{
			q++;
			cout<<i;
			z[e+1-i]=z[i];
		}
	}
	cout<<q;
	return 0;
 } 
