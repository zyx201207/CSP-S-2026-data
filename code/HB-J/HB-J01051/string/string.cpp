#include<bits/stdc++.h>
using namespace std;
struct pre
{
	int g;
	char w;
}a[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].g>>a[i].w;
	}
	int r=0,l=n-1,t=0,ans=0;
	while(r<l)
	{
		if(a[r].g>a[l].g)
		{
			if(a[r].w!=a[l].w) ans+=a[l].g;
			t=a[r].g-a[l].g;
			l--;
			a[r].g=t;
			
		}
		if(a[l].g>a[r].g)
		{
			if(a[r].w!=a[l].w) ans+=a[r].g;
			t=a[l].g-a[r].g;
			r++;
			a[l].g=t;
		}
		if(a[r].g==a[l].g)
		{
			if(a[r].w!=a[l].w) ans+=a[l].g;
			l--;
			r++;
		}		
	}
	cout<<ans;
	return 0;
}
