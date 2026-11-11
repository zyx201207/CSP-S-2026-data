#include<bits/stdc++.h>
using namespace std;
int n;
int l[200005];
char a[200005];
long long ans;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> l[i];
		cin >> a[i];
	}
	int s=1,cs=l[1],e=n,ce=l[n];
	while(s<e)
	{
		if(a[s]==a[e])
		{
			if(cs>ce)
			{
				cs-=ce;
				e--;
				ce=l[e];
			}
			else if(cs==ce)
			{
				s++;
				e--;
				cs=l[s];
				ce=l[e];
			}
			else
			{
				ce-=cs;
				s++;
				cs=l[s];
			}
		}
		else
		{
			if(cs>ce)
			{
				ans+=ce;
				cs-=ce;
				e--;
				ce=l[e];
			}
			else if(cs==ce)
			{
				ans+=cs;
				s++;
				e--;
				cs=l[s];
				ce=l[e];
			}
			else
			{
				ans+=cs;
				ce-=cs;
				s++;
				cs=l[s];
			}
		}
	}
	cout << ans;
	return 0;
}
