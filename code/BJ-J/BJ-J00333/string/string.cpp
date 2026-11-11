#include <bits/stdc++.h>
using namespace std;
int n,shu[10000005],ans,sum;
char mu[10000005];
string cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>shu[i]>>mu[i];
        sum+=shu[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=shu[i];j++)
        {
            cnt=cnt+mu[i];
        }
    }
    int l=1,r=sum;
    while (l!=r&&r-l!=1)
    {
        if (cnt[l]!=cnt[r])
        {
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans;

}
