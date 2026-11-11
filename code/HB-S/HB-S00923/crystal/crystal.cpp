#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans1=0;
    for(int i=1;i<=n;i++)
    {
        int a1=a[i],ans=0;
        int o=m;
        for(int j=i;j>=1;j--)
        {
                long long a2=a1-a[j];
            if(a1>=a[j]&&(o-a2)>=0)
            {
                o-=a2;

                ans++;
            }
            else
            {
                break;

            }

        }
        ans1=max(ans1,ans);
            ans=0;
    }
    cout<<ans1;
    return 0;
}
