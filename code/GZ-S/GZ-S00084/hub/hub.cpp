//GZ-S00084,罗子淇,贵阳市南明区第二实验中学；
#include<bits/stdc++.h>
intt main()
{
    int n,m,a,b,c,t[100005];
    freopen("subway.in","r",stdin)
    freopen("subway.out","w",stdout)
    cin>>a>>b>>m>>c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>t[i];
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(sum>=n)
        {
            cout<<sum;
        }
    }
    for(int i=1,i<=n;i++)
    {
        if(a<b)
        {
                l=i-1;
        }
    }
    cout<<sum;
    return 0;

}
