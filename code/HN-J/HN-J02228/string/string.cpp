#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using ll=long long;
int n,a[N];
char c[N];
string s;
ll sum;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i]>>c[i];
    	for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
	}
	string t=s;
	reverse(t.begin(),t.end());
	ll len=s.size();
	for(ll i=0;i<len;i++)
    {
        if(s[i]!=t[i])
        {
            s[i]=t[i];
            t[len-i-1]=s[i];
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
