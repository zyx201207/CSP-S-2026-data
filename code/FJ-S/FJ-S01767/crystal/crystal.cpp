#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],s[100100],ss[100100],x,maxn,minn=100000,ans;
bool wl=true,lw=true;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x+=a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		if(a[i]>=0) s[a[i]]++;
		else {long long t=abs(a[i]);ss[t]++;}
		if(wl==true)
		{
			long long p=abs(a[1]-a[0]),q=abs(a[i]-a[i-1]);
			if(p!=q) wl=false;
		}
		if(a[i]!=i) lw=false;
	}
	if(wl==true||lw==true)
	{
		long long p,q;
		while(p+m>=q*a[q])
		  {q++;p+=a[q];}
		cout<<q-1;
		return 0;
	}
	for(int i=maxn;i>=minn;i--)
	{
		long long k1=m,k2=i,k3=0,anss=0;
		if(s[i]>0)
		{
			anss+=s[i];
			while(k1>k3&&k2>=minn)
			{
				long long k4;
				k2--;
				if(k2>=0) k4=s[k2];
				else k4=ss[k2];
				k3++;
				k4=min(k1/k3,k4);
				anss+=k4;
				k1-=k3*k4;
			}
			ans=max(ans,anss);
		}
	}
	cout<<ans;
	return 0;
}