#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,len=0,ans=0,a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld %c",&a[i],&c[i]),len+=a[i];
	int mid=(len+1)/2;
	int suml=0,sumr=0,pos=a[n],r=n,l=1;
	for(;;l++)
	{
		if(suml+a[l]>=mid)break;
		suml+=a[l];
		while(1)
		{
			if(sumr+pos>suml)
			{
				if(c[l]!=c[r])ans+=suml-sumr;
				pos-=suml-sumr;sumr=suml;
				break;
			}
			if(c[l]!=c[r])ans+=pos;
			sumr+=pos;
			r--;pos=a[r];
		}
		//cout<<l<<"-"<<suml<<" "<<r<<"-"<<sumr<<" "<<pos<<" "<<ans<<endl;
	}
	while(r>l)
	{
		if(c[l]!=c[r])ans+=pos;
		r--,pos=a[r];
	}
	printf("%lld",ans);
}
