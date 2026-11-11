#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s[200001],p[31],maxn=-1,ans,o[200001],l=0,r=m-1,g,u,v=0,fans,k=0,ans2;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		if(s[i]>=maxn)
		{
			maxn=s[i];
		}
	}
	cout<<maxn;
    return 0;
}


