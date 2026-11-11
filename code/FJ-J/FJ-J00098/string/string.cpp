#include <bits/stdc++.h>
using namespace std;
int n,tmp;
long long cnt=0;
bool flag=true;

struct st
{
	int a;
	char c;
} a[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].c;
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].c!=a[r].c)
		{
			if(a[l].a>a[r].a) cnt+=a[r].a;
			else cnt+=a[l].a;
		}
		if(a[l].a>a[r].a)
		{
			tmp=a[l].a-a[r].a;
			flag=true;
		}
		else if(a[l].a==a[r].a) tmp=0;
		else
		{
			tmp=a[r].a-a[l].a;
			flag=false;
		}
		if(flag)
		{
			a[l].a-=tmp;
			r--;
		}
		else
		{
			a[r].a-=tmp;
			l++;
		}
	}
	cout<<cnt;
	return 0;
}

