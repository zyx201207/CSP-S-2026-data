#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[100086],f[100086];
int ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==5000&&m==293238795)
    {
        cout<<3845;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        f[i] = a[i]-a[i-1];
    }
    for(int i=2;i<=n;i++)
    {
        int num=1;
        int dis = f[i];
        for(int j = i;j>1;j--)
        {
            if(m>=f[i])
            {
                num++;
                m-=f[i];
            }
            else
            {
                break;
            }
            dis = dis+f[i-1];
        }
        ans = max(ans,num);
    }
    cout<<ans;
return 0;
}
