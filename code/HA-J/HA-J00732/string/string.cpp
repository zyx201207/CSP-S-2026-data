#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,j,n,d[200001],le=0,ri=0,ans=0;
	char s[200001],qi,mo;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>d[i]>>s[i];
	}
	le=d[1],qi=s[1];
	ri=d[n],mo=s[n];
	if(qi!=mo)ans+=min(le,ri);
	for(i=2,j=n-1;i<=j;)
	{
		if(le<=ri)
		{
			qi=s[i];
			if(mo!=qi)
			{
				if(le+d[i]<ri)ans+=d[i];
				else ans+=ri-le;
			}
			le+=d[i];
			i++;
		}
		else
		{
			mo=s[j];
			if(mo!=qi)
			{
				if(ri+d[j]<le)ans+=d[j];
				else ans+=le-ri;
			}
			ri+=d[j];
			j--;
		}
	}
	cout<<ans;
	return 0;
}
