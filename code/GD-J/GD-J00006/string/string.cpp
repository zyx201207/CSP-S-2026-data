#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,l,ma,ans,sum;
long long le,ri,lp;
long long a[N];
char c[N];
string s;
int main()	{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	{
		cin>>a[i]>>c[i];
		l+=a[i];
		ma=max(ma,a[i]);
	}
	if(l==1)	{
		cout<<0;
		return 0;
	}
	if(ma<=500)	{
		
		for(int i=1;i<=n;i++)	{
			for(int j=1;j<=a[i];++j)	s+=c[i];
		}
		s=" "+s;
		for(int i=1;i<=l/2;i++)	{
			if(s[i]!=s[l-i+1])	++ans;
		}
		cout<<ans;
		return 0;
	}
	int ll=1,rr=n;
	if(l&1)	{
		for(int i=1;i<=n;i++)	{
			if(sum+a[i] >= (l+1)/2)		{
				--a[i];
				break;
			}
			else sum+=a[i];
		}
		--l;
	}
	sum =0;
	for(int i=1;i<=n;i++)	{
		if(sum+a[i]>=l/2)	{
			ri =sum+a[i]-l/2;
			le =a[i]-ri;
			lp=i;
			break;
		}else sum+=a[i];
	}
//	for(int i=1;i<=n;i++)	cout<<a[i]<<' ';
//	cout<<'\n';
//	cout<<le<<' '<<ri<<' '<<lp<<'\n';
	while(ll<rr)	{
		if(!a[ll]){
			++ll;
			continue;
		}
		if(!a[rr]){
			--rr;
			continue;
		}
		if(rr==lp)	{
			if(c[lp]==c[ll])	ans += a[ll];
			ri-=a[ll];
			++ll;
			continue;
		}
		if(ll==lp)	{
			if(c[lp]==c[rr])	ans+=a[rr];
			le-=a[rr];
			--rr;
			continue;
		}
		if(c[ll] == c[rr]){
			if(a[ll]==a[rr])	{
				ans+=a[ll];
				++ll,--rr;
			}
			else if(a[ll] > a[rr])	{
				ans += a[rr];
				a[ll] -= a[rr];
				--rr;
			}
			else {
				ans += a[ll];
				a[rr] -= a[ll];
				++ll; 
			} 
		}
		else {
			if(a[ll]==a[rr])		++ll,--rr;
			else if(a[ll] > a[rr])	{
				a[ll] -= a[rr];
				--rr;
			}
			else {
				a[rr] -= a[ll];
				++ll; 
			} 
		}
	}
	cout<<l/2-ans;
	return 0;
}
/*
Trick||Treat!
3
2 a
2 b
1 c

2
2 a
3 a
*/
