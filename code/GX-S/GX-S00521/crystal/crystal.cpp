#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[500005],b[500005],ans=-1;
int main()
{
    freopen("crystal.in","r","stdin");
    freopen("crystal.out","s","stdout");
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        b[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        int zhi1=b[i],zhi2=b[i+1],ans1=0,ans2=0;
        for(int j=i+1;j<=n;j++)
        {
            if(zhi1+b[j]<=m)
            {
                zhi1+=b[j];
                ans1++;
            }
            else if(zhi1+b[j]>m && zhi2+b[j]<=m)
            {
                zhi2+=b[j];
                ans2++;
            }
        }
        ans=max(ans1,ans);
        ans=max(ans,ans2);
    }
    cout << ans;
    return 0;
}
