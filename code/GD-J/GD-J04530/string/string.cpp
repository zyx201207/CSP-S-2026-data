#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=j;)
	{
		if(a[i]==a[j])
		{
			if(c[i]==c[j]) a[i]=0,a[j]=0,i++,j--;
			else ans+=a[i],a[i]=0,a[j]=0,i++,j--;
		}
		else if(a[i]>a[j])
		{
			if(c[i]==c[j]) a[i]-=a[j],a[j]=0,j--;
			else ans+=a[j],a[i]-=a[j],a[j]=0,j--;
		}
		else
		{
			if(c[i]==c[j]) a[j]-=a[i],a[i]=0,i++;
			else ans+=a[i],a[j]-=a[i],a[i]=0,i++;
		}
	}
	cout<<ans;
}
