#include<bits/stdc++.h>
using namespace std;
int a[200020];
int main()
{
    freopen("and.in","r",stdin);
    freopem("and.out","r",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m=1)
    {
        int maxs=a[1];
        for(int i=2;i<=n;i++)
        {
            if(a[i]>maxs) maxs=a[i];
        }
        cout<<maxs;
    }
    else if(m=n)
    {
        int maxs=(a[1] || a[2]);
        for(int i=3;i<=n;i++)
        {
            maxs=(maxs || a[i]);
        }
        cout<<maxs;
    }
    else if(m=2)
    {
        int maxs=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if((a[i] || a[j])>maxs) maxs=(a[i] || a[j]);
            }
        }
        cout<<maxs;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
