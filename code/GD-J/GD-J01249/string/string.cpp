#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long s[N],v,ans;
int n,a[N];
char c[N],o;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],s[i]=a[i]+s[i-1];
	int j=n;
	for(int i=1;s[i]<=s[n]/2;i++)
	{
		long long ql=s[i-1]+1,qr=s[i],hl=s[n]-s[j]+1,hr=s[n]-s[j-1];
		if(ql>hl)
		{
			if(qr>=hr)
			{
				if(c[i]!=c[j])
					ans+=hr-ql+1;
				j--;				
			}
			else
			{
				if(c[i]!=c[j])
				{
					ans+=hr-ql+1;
					continue;				
				}
			}
		}
		hl=s[n]-s[j]+1,hr=s[n]-s[j-1];
		while(ql<=hl && qr>=hr)
		{
			if(c[i]!=c[j])
				ans+=hr-hl+1;
			j--;
			hl=s[n]-s[j]+1,hr=s[n]-s[j-1];
		}
		if(qr>=hl)
		{
			if(c[i]!=c[j])
				ans+=qr-hl+1;
		}
	}
	cout<<ans;
	return 0;
}
