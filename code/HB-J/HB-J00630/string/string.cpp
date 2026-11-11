#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,a[N],cnt;
char c[N];
bool ok;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(ll i=1;i<=n;i++)
        cin >> a[i] >> c[i];
    ll i=1,j=n;
    while(i<j)
    {
        if(c[i]==c[j])
            ok=0;
        else
            ok=1;
        if(a[i]<a[j])
        {
            a[j]-=a[i];
            if(ok)
                cnt+=a[i];
            i++;
        }
        else if(a[i]>a[j])
        {
            a[i]-=a[j];
            if(ok)
                cnt+=a[j];
            j--;
        }
        else
        {
            if(ok)
                cnt+=a[i];
            i++,j--;
        }
    }
    cout << cnt;
    return 0;
}
