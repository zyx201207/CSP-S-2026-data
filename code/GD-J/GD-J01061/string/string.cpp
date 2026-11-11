#include<bits/stdc++.h>
using namespace std;
struct in{long long sl;char ch;}m[200001];
long long n,xg,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&m[i].sl,&m[i].ch);
	}
	for(int i=1,j=n;i<j;)
	{
		 
		xg=min(m[i].sl,m[j].sl);
		if(m[i].ch!=m[j].ch)
		{
			ans+=xg;
		}
		m[i].sl-=xg,m[j].sl-=xg;
		if(m[i].sl==0) i++;
		if(m[j].sl==0) j--;
	}
	cout<<ans;
	return 0;
}
