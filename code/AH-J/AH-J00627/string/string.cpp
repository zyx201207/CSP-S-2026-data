#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200000+10;
ll n,len;
string s1;
struct Node
{

   ll a;
   char c;
}a[N],b[N];
void solve1()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i].a>>a[i].c;
        for(ll j=1;j<=a[i].a;j++)
        {
            s1+=a[i].c;
        }
    }
    ll cnt=0;
    string s2=s1;
    reverse(s2.begin(),s2.end());
    if(s1!=s2)
    {
        for(ll i=0;i<(s1.size()+1)>>1;i++)
        {
            if(s2[i]!=s1[i])
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    solve1();
    return 0;
}
