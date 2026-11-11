#include <bits/stdc++.h> 
using namespace std;
long long n,jg;
struct APP{
	long long a;
	char b;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	APP c[n+10];
	for (long long i=1;i<=n;i++)
	{
		cin>>c[i].a>>c[i].b;
	}
	long long s=1,e=n;
	while (s<e)
	{
		if (c[s].b==c[e].b)
		{
			if (c[s].a<c[e].a)
			{
				c[e].a-=c[s].a;
				s++;
			}
			else if (c[s].a==c[e].a)
			{
				s++;
				e--;
			}
			else
			{
				c[s].a-=c[e].a;
				e--;
			} 
		}
		else
		{
			if (c[s].a<c[e].a)
			{
				c[e].a-=c[s].a;
				jg+=c[s].a;
				s++;
			}
			else if (c[s].a==c[e].a)
			{
				jg+=c[s].a;
				s++;
				e--;
			}
			else
			{
				c[s].a-=c[e].a;
				jg+=c[e].a;
				e--;
			} 	
		}
	}
	cout<<jg;
	return 0;
}
