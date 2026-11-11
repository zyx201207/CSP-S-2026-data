#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
long long ans,l,k,n,a[N],f[N],t[N],s[2*N],s1[N],s2[N];
char c[N],c1[2*N],c2[2*N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		f[i]=t[i-1]+1;
		t[i]=t[i-1]+a[i];
		l+=a[i];
	}
	k=l/2;
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		s[2*i]=t[i];
		s[2*i-1]=l-f[n-i+1]+1;
		s1[i]=s[2*i];
		s2[i]=s[2*i-1];
	}
	sort(s,s+2*n+1);
//	cout<<"s: ";
//	for(int i=1;i<=2*n;i++)
//	{
//		cout<<s[i]<<" ";
//	}
//	cout<<"\ns1: ";
//	for(int i=1;i<=n;i++)
//	{
//		cout<<s1[i]<<" ";
//	}
//	cout<<"\ns2: ";
//	for(int i=1;i<=n;i++)
//	{
//		cout<<s2[i]<<" ";
//	}
//	cout<<"\n";
	int sa=1,sb=1;
	for(int i=1;i<=2*n;i++)
	{
		long long nt=s[i],p=s[i]-s[i-1];
//		cout<<"nt: "<<nt<<" i: "<<i<<" p: "<<p<<"\n";
//		cout<<"  s1: "<<s1[sa]<<" s2: "<<s2[sb]<<"\n";
//		cout<<"  st: sa: "<<sa<<" sb: "<<sb<<"\n";
		if(s1[sa]<nt)
		{
			sa++;
		}
		if(s2[sb]<nt)
		{
			sb++;
		}
//		cout<<"  en: sa: "<<sa<<" sb: "<<sb<<"\n";
		c1[i]=c[sa],c2[i]=c[n-sb+1];
//		cout<<"  c1: "<<c1[i]<<" c2: "<<c2[i]<<"\n";
		if(c1[i]!=c2[i])
		{
			ans+=p;
		}
//		cout<<"  ans: "<<ans<<"\n";
	}
	cout<<ans/2;
	return 0;
}
