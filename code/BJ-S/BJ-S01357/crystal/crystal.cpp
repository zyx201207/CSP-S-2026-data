#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long maxa=-2e9;
    for(int i=1;i<=n;i++)
    {
        long long cnt=0,m1=m,ma=-2e9;
        for(int j=1;j<=n;j++)
        {
            if(a[j]>a[i])
            {
                ma=max(ma,a[j]);
                continue;
            }
            if(a[i]==a[j])
            {
                cnt++;
                ma=max(ma,a[i]-a[j]);
            }
            else if(m1>=(a[i]-a[j]))
            {
                m1-=(a[i]-a[j]);
                cnt++;
                ma=max(ma,a[i]-a[j]);
            }
            else
                continue;
        }
        if(m1!=0&&ma<=a[i])
            cnt--;
        maxa=max(maxa,cnt);
    }
    cout<<maxa<<endl;
    return 0;
}
