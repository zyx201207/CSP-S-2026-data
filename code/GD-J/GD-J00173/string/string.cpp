#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[200005];
char c[200005];
ll l,r,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	l=1;
	r=n;
	ll ct1=a[1],ct2=a[n];
	while(l<r)
	{
		if(l==r) break;
		if(ct1==ct2)
		{
			if(c[l]!=c[r]) ans=ans+ct1;
			l++,r--;
			ct1=a[l],ct2=a[r];
		}
		else if(ct1<ct2)
		{
			if(c[l]!=c[r]) ans+=ct1;
			ct2-=ct1;
			l++;
			ct1=a[l];			
		}
		else 
		{
			if(c[l]!=c[r]) ans+=ct2;
			ct1-=ct2;
			r--;
			ct2=a[r];
		}
		//cout<<l<<' '<<r<<' '<<ans<<endl;
	}
	cout<<ans; 
	
	return 0; 
}


