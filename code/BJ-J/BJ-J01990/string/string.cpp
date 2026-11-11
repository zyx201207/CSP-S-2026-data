#include<bits/stdc++.h>
using namespace std;
long long n,a[1010100],ans;
char b[1010100];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    int l=1,r=n;
    while(l<r)
    {
        long long g=min(a[l],a[r]);
        if(b[l]!=b[r]) ans+=g;
        a[l]-=g;
        if(a[l]==0) l++;
        a[r]-=g;
        if(a[r]==0) r--;

    }
    cout<<ans;
    return 0;
}

