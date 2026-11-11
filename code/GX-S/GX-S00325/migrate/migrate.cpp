#include<bits/stdc++.h>
using namespace std;
int n,a[309],s,d,c,r,f,ee;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>r;
    for(int p=1;p<=r;p++)
    {
        cin>>n>>d;
        s=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=n;j>i;j--)
            {
                ee=0;
                if(j-i<2||a[j]-a[i]>d*(j-i))
                {
                    continue;
                }
                ee=(j-i);
                if(ee%2!=0)
                {
                    s++;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}

