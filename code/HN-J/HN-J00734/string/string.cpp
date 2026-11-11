#include<bits/stdc++.h> 
using namespace std;
int a[200005],n;
char b[200005];
long long ans=0;
int main()
{
	int t;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
//		scanf("%d %c",&a[i],&b[i]);
		cin>>a[i]>>b[i];
	}
	t=n;
	for(int i=1;i<t;)
	{
//		printf("%d %d  %d %d ",i,t,a[i],a[t]);
		if(a[i]<a[t])
		{
			if(b[i]!=b[t])
			{
				ans+=a[i];
			}
			a[t]-=a[i];
			i++;
		}
		else if(a[i]==a[t])
		{
			if(b[i]!=b[t])
			{
				ans+=a[i];
			}
			t--;
			i++;
		}
		else
		{
			if(b[i]!=b[t])
			{
				ans+=a[t];
			}
			a[i]-=a[t];	
			t--;	
		}
//		printf("%lld\n",ans);
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
