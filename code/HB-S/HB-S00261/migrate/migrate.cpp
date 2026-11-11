#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')f=0;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return f?x:-x;
}
int c,t,n,d,x[2060606];
bool dc;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            x[i]=read();
            if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2])dc=1;
        }
        if(!dc)//pf1
        {
            int c=x[2]-x[1];
            int cc=(d-c)/c;
            if(c>n-2)cout<<0<<endl;
            else
            {
                int s=0;
                for(int i=0;i<=c;i++)s+=(n-2-i);
                cout<<s<<endl;
            }
        }
        else //pf2
        {
            int s=0;
            for(int i=1;i<=n;i++)
                s+=lower_bound(x+1,x+n+1,x[i]+d+1)-upper_bound(x+1,x+n+1,x[i]+2*d+1);
            cout<<s-1<<endl;
        }
    }
}
