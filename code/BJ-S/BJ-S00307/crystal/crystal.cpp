#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m,a[N],b=1,c,ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.ont","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c=a[i]-a[i-1];
    }
    for(int i=m;i>=1;i-=b)
    {
        ans++;
        b+=c;
    }
    cout<<(ans+1)%n;
    return 0;
}
