#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010100],cnt[1010],ok[1010100],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=30;j>=0;j--)
        {
            if((a[i]>>j)&1) cnt[j]++;
        }
    }
    for(int j=30;j>=0;j--)
    {
       // cout<<j<<" "<<cnt[j]<<endl;
        if(cnt[j]>=m)
        {
            ans+=(1<<j);
            for(int i=1;i<=n;i++)
            {
                if(!ok[i])
                {
                    if(!((a[i]>>j)&1))
                    {
                        for(int k=30;k>=0;k--)
                        {
                            if((a[i]>>k)&1) cnt[k]--;
                        }
                        ok[i]=1;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

