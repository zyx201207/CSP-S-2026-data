#include<bits/stdc++.h>
using namespace std;
char c[200010];
int n,t=1,w;
long long ans,a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	w=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(t<w)
	{
		if(a[t]>a[w])
		{
			if(c[t]!=c[w])
			{
				ans+=a[w];
			}
			a[t]-=a[w];
			a[w]=0;
			w--;			
		}
		if(a[t]==a[w])
		{
			if(c[t]!=c[w])
			{
				ans+=a[w];
			}
			a[t]=0;
			a[w]=0;
			w--;
			t++;	
		}
		if(a[t]<a[w])
		{
			if(c[t]!=c[w])
			{
				ans+=a[t];
			}
			a[w]-=a[t];
			a[t]=0;
			t++;			
		}
	}
	cout<<ans;
}
