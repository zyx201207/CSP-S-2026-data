#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+10;
ll n,ans=0;
struct qwq
{
    ll len;
    char name;
    ll sum;
}a[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].len>>a[i].name;
    }
    char ed=a[n].name;
    ll edd=n;
    int i=1;
    while(i<edd)
    {
        while(a[i].name!=ed)
        {
            if(i>edd) break;
            if(a[i].len>a[edd].len)
            {
                ans+=a[edd].len;
                a[i].len-=a[edd].len;
                edd--;
                ed=a[edd].name;
            }
            else if(a[i].len<a[edd].len)
            {
                ans+=a[i].len;
                a[edd].len-=a[i].len;
                i++;
            }
            else if(a[i].len==a[edd].len)
            {
                ans+=a[i].len;
                i++;
                edd--;
                ed=a[edd].name;
            }
        }
        if(a[i].len>a[edd].len)
        {
            a[i].len-=a[edd].len;
            edd--;
            ed=a[edd].name;
        }
        else if(a[i].len<a[edd].len)
        {
            a[edd].len-=a[i].len;
            i++;
        }
        else if(a[i].len==a[edd].len)
        {
            edd--;
            ed=a[edd].name;
            i++;
        }
    }
    cout<<ans;
    return 0;
}
