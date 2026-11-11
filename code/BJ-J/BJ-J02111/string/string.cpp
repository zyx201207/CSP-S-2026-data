#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,sum,cnt;
char c;
string s;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld %c",&a,&c);
        sum+=a;
        for(ll j=1;j<=a;j++)
        {
            s=s+c;
        }

    }


    s = " "+s;

    for(ll i=1;i<=sum/2;i++)
    {

        if(s[i]!=s[sum+1-i])
        {
            cnt++;
        }

    }
    printf("%lld",cnt);
    return 0;
}