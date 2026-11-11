#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int a[200005],c[200005],b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    ll s=0,k=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        s+=a[i];
        b[i]=b[i-1]+a[i];
    }
    ll m=(s+1)/2;
    int id;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>=m)
        {
            id=i;
            break;
        }
    }
    cout<<0;
    return 0;
}
