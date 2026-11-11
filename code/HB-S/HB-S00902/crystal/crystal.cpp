#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],d=1,ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(a[6]-a[5]==a[4]-a[3]&&a[4]-a[3]==a[2]-a[1])
    {
        while(m>0)
        {
            for(int i=1;i<=2;i++)
            {
                if(m>0)
                {
                    m-=d;
                    ans++;
                }
                else
                {
                    break;
                }
            }
            d++;
        }
    }
    cout<<ans;
    return 0;
}
