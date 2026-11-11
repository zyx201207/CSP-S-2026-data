#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a;
char c;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll mid = 0;
    cin.tie(0),cout.tie(0);
    scanf("%lld",&n);
    for(register int i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        cin>>c;
        mid += a;
        while(a--){
            s+=c;
        }
    }
    ll ans=0,mid1=mid/2-1;
    for(register int i=0;i<=mid1;i++)
    {
        if(s[i]!=s[i+mid1+1])ans++;
    }
    printf("%lld",ans);
    return 0;
}
