#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[200005],ans=0;
    cin>>n>>m;
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j]==i)
            {
                ans++;
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}
