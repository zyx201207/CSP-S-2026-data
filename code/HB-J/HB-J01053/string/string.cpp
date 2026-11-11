#include<bits/stdc++.h>
using namespace std;
int n,j;
long long a[100010],w,l,r,ans1,ans;
char c,k;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;r=n-1;
    cin>>a[0]>>c;
    w+=a[0];k=c;ans1+=a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i]>>c;
        if(c==k) w+=a[i];
        ans1+=a[i];
    }
    while(l<r)
    {
        ans+=a[l]-a[r];
        l++;r--;
    }
    if(ans<0) ans=ans*-1;
    if(ans1-ans-w<0) cout<<0;
    else cout<<ans1-ans-w;
    return 0;
}
