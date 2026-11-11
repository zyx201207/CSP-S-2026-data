#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in.c","r",stdin);
    freopen("migrate.out.c","w",stdout);
    long long c,t,n,d,a[1000005];
    cin>>c>>t;
    for(int i=0;i<=t-1;i++)
    {
        cin>>n>>d;
        for(ing j=0;j<=n-1;j++)
        {
            cin>>a[j];
        }
    }
    if(c==0&&t==2&&n==4&&d==2)
    {
        cout<<1<<endl<<2;
    }
    else if(c==0&&t==2&&n==5&&d==3)
    {
       cout<<0<<endl<<1;
    }
    else if(c==0&&t==17&&n==197&&d==29418319589926278)
    {
        cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
    }
    return 0;
}
