#include<iostream>
using namespace std;
struct st
{
    int b;
    char c;
}a[100005];
st d[100005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].b>>a[i].c;

    }

    for(int i=n;i>=1;i--)
    {
        d[n-i+1].b=a[i].b;
        d[n-i+1].c=a[i].c;

    }

    long long ans=0;
    long long cnt3=a[1].b,cnt4=d[1].b;
    int cnt1=1,cnt2=1;
    long long zz1=0,zz2=0;
    for(int i=1;i<=2*n;i++)
    {
        if(cnt3<cnt4)
        {
            zz2=cnt3;
            if(a[cnt1].c!=d[cnt2].c)ans+=(zz2-zz1);
            zz1=zz2;
            cnt3+=a[++cnt1].b;
        }
        else if(cnt3==cnt4)
        {
            zz2=cnt3;
            if(a[cnt1].c!=d[cnt2].c)ans+=(zz2-zz1);
            zz1=zz2;
            cnt3+=a[++cnt1].b;
            cnt4+=d[++cnt2].b;
        }
        else
        {
            zz2=cnt4;
            if(a[cnt1].c!=d[cnt2].c)ans+=(zz2-zz1);
            zz1=zz2;
            cnt4+=d[++cnt2].b;
        }
    }
    cout<<ans/2;
}

