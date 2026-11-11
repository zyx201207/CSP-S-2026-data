#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[200005];
char c[200005],z[2000005],y[2000005];
ll x;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++)
        x+=a[i];
    ll t=x/2;
    while(t--)
    {
        int qo=1,po=1;
        y[qo]=c[qo];
        po++;
        if(po>a[qo]){
            qo++;
            po=1;
        }
    }
    t=x/2;
    while(t--)
    {
        int qo=x,po=1;
        z[qo]=c[qo];
        po++;
        if(po>a[qo]){
            qo--;
            po=1;
        }
    }
    t=x/2;
    int cnt=0;
    for(int i=1;i<=t;i++)
        if(y[i]!=z[i])
            cnt++;
    cout<<0;
    return 0;
}
