#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,p,d=0,q,ans=0;
	string s,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p>>m;
		d+=p;
		for(int i=1;i<=p;i++)
		{
			s+=m;
		}
	}
	q=d;
	if(q%2!=0)
	{
		q=q/2-1;
	}
	d--; 
	for(int i=0;i<=q;i++)
	{
		if(s[d]!=s[i])
		{
			ans++;
		}
		d--;
	}
	cout<<ans;
    return 0;
}


