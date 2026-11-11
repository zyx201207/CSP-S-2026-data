#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        long long y;
        cin>>y;
        a[i]=y;
    }
    int ma=-1;
    for(int i=1;i<=n;i++)
    {
        int a[i],x=0;
        for(int j=i+1;j<=n;j++)
        {
            x++;
            c&=a[j];
            if(x=m-1)
                break;
        }
        if(c>ma)
            ma=c;
    }
    cout<<ma;
    return 0;
}
