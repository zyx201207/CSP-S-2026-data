#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n=0,m=0,maxx=0;
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1)
    {
        sort(a.begin(),a.end());
        cout<<a[n];
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            if(m+i<=n)
            {
                int sum=a[i];
                for(int j=i+1;j<=m+i;j++)
                {
                    sum=sum&a[j];
                }
                maxx=max(maxx,sum);
            }
        }
        cout<<maxx;
    }
    else if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++)ans=ans&a[i];
        cout<<ans;
    }
    return 0;
}
