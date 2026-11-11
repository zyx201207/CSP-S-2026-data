#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll qread()
{
	char c=getchar();
	ll x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f*=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}


vector<ll>w,t;//t是前缀和
ll n,m,tp,tp1,tp2,l,ans;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=qread();
	m=qread();
	w.resize(n);
	t.resize(n);
	for(int p=0;p<n;p++)w[p]=qread();
	w.push_back(-1e19);
	t.push_back(-1e19);
	sort(w.begin(),w.end());
	t[1]=w[1];
	for(int p=2;p<=n;p++)t[p]=w[p]+t[p-1];
	l=1;
	for(int p=1;p<=n;p++)
	{
		while(l<p&&l<n&&w[p]*(p-l)-t[p-1]+t[l-1]>m)l++;
		ans=max(ans,p-l+1);
	}
	cout<<ans;
	return 0;
}
