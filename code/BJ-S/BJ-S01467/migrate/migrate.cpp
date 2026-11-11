#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cr[1000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int o=0;o<t;o++)
    {
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++)
        cin>>a[i];
        cr[0]=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]-a[i-1]<=d)
            {
                cr[i]=a[i];
                continue;
            }
            n--;
        }
        if(n==2*d)
        cout<<1<<"\n";
        else if(n>2*d)
        cout<<1+n-2*d<<"\n";
    }
}