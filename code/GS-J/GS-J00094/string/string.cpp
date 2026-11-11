#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>>
using namespace std;
char b;
int ans,n,aa,bb,cc;
struct c
{
	int s;
	char z;
}d[200005];
bool cmp(c a,c b)
{
	if(a.z!=b.z)
		return a.z<b.z;
	else
		return a.s<b.s;
}
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
   cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>d[i].s>>d[i].z;
	}
	sort(d,d,cmp);
	for(int i=1;i<=n;i+=2)
	{
		if(!aa)
		{
			if(d[i].z!=d[i+1].z)
			{
				ans+=min(d[i].s,d[i+1].s);
			}
			aa=abs(d[i].s-d[i+1].s);
		}
		else
		{
			if(d[i-2].z==d[i].z)
			{
				cc=d[i].s-aa;
			}
			if(d[i].z==d[i+1].z)
			{
				aa=d[i+1].s-cc;
			}
		}
		
	}
	cout<<ans;
    return 0;
}
