#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;

int n,a[MAXN];
long long ans=0;
char c[MAXN];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    long long l=1,r=n,resl=a[1],resr=a[n];
    while(l<r)
    {
        if(resl>resr)
        {
            if(c[l]==c[r])
            {
                resl-=resr;
                r--;
                resr=a[r];
            }
            else
            {
                ans+=resr;
                resl-=resr;
                r--;
                resr=a[r];
            }
        }
        else if(resl<resr)
        {
            if(c[l]==c[r])
            {
                resr-=resl;
                l++;
                resl=a[l];
            }
            else
            {
                ans+=resl;
                resr-=resl;
                l++;
                resl=a[l];
            }
        }
        else if(resl==resr)
        {
            if(c[l]==c[r])
            {
                r--,l++;
                resr=a[r];
                resl=a[l];
            }
            else
            {
                ans+=resr;
                r--,l++;
                resr=a[r];
                resl=a[l];
            }
        }
    }
    cout<<ans;
    return 0;
}
