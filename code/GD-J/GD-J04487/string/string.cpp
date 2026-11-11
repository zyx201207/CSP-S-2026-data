#include<bits/stdc++.h>
#define ll long long
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define itn int
#define asn ans
using namespace std;
ll ans,n;
const ll N=2e5+5;
struct node
{
	ll a;
	string c;
}w[N];
int main()
{
	fre("string");
	cin>>n;
	cin.tie(nullptr);
	for(ll i=1;i<=n;i++)cin>>w[i].a>>w[i].c;
	for(ll i=1;i<=n/2;i++)
	{
		if(w[i].c!=w[n-i+1].c)ans+=max(w[i].a,w[n-i+1].a);
	}
	cout<<ans;
    return 0;
}

