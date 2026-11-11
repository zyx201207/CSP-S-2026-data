#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],ans;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i]>>c[i];
    ll i=1,j=n;
    while(i<j)
    {
        if(a[i]<a[j])
        {
            if(c[i]!=c[j])ans+=a[i];
            a[j]-=a[i];
            i++;
        }
        else if(a[i]==a[j])
        {
            if(c[i]!=c[j])ans+=a[i];
            i++;
            j--;
        }
        else
        {

            if(c[i]!=c[j])ans+=a[j];
            a[i]-=a[j];
            j--;
        }
    }
    cout<<ans;
    return 0;
}
