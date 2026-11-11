//GZ-J00185 ³ÂÕıÁú
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
vector<char> c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,a;
	char b;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(a);
        c.push_back(b);
    }
	ll l=0,r=n-1;
	ll cnt=0;
	while(l<r)
    {
        ll t=min(v[l],v[r]);
        if(c[l]!=c[r])
        {
            cnt+=t;
        }
        v[l]-=t;
        v[r]-=t;
        if(v[l]==0) l++;
        if(v[r]==0) r--;
    }
    cout<<cnt;
	return 0;
}
