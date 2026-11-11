#include<bits/stdc++.h>
using namespace std;
int c,t,p,n,b,a[2000010];
bool f=true;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>b;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i==2) p=a[i]-a[i-1];
            if(i>=2)
            {
                if(a[i]-a[i-1]!=p) f=false;
            }
        }
        if(f && n>=3) cout<<n-(b+1)<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
