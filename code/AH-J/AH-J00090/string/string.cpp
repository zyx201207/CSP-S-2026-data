#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node
{
	int a;
	char c;
}v[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>v[i].a>>v[i].c;
	int l=1,r=n;
	while(l<r)
	{
		if(v[l].a>v[r].a)
		{
			if(v[l].c==v[r].c)
			{
				v[l].a-=v[r].a;
				r--;
			}
			else
			{
				ans+=v[r].a;
				v[l].a-=v[r].a;
				r--;
			}
		}
		else if(v[l].a<v[r].a)
		{
			if(v[l].c==v[r].c)
			{
				v[r].a-=v[l].a;
				l++;
			}
			else
			{
				ans+=v[l].a;
				v[r].a-=v[l].a;
				l++;
			}
		}
		else
		{
			if(v[l].c==v[r].c)
			{
				v[r].a-=v[l].a;
				l++;
				r--; 
			}
			else
			{
				ans+=v[l].a;
				v[r].a-=v[l].a;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

