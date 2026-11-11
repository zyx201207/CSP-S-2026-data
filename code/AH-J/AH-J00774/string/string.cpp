#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
string s;
ll n,x[N],sum,l;
char ch[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>x[i]>>ch[i];
        l+=x[i];
    }
    cout<<l/2;
    return 0;
}
