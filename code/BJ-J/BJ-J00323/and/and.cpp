#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010]
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool f=false;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==pow(2,j)-1)
            {
                f=true;
                a[i]=0;
            }
        }
    }
    for(int i=1;i<=n;i++) Max=max(Max,a[i])
    if(f) cout<<Max;
    else cout<<0;
    return 0;
}
