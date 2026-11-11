#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll n,a[maxn],len,s[maxn],ans;
char c[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
		s[i]=len;
	}
	ll l=len/2,r=len/2+1;
	if(len%2!=0) r++;
	ll i=1,j=1;
	while(l>s[i]) i++;
	while(r>s[j]) j++;
	while(l>=1)
	{
		if(c[i]!=c[j]) ans++;
		l--,r++;
		if(l==s[i-1]) i--;
		if(r>s[j]) j++;
	}
	cout<<ans;
	return 0;
}
