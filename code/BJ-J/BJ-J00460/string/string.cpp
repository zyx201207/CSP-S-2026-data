#include<bits/stdc++.h>
using namespace std;
string a1;
int n;
long long ans1=0;
void z()
{
    struct no{
    long long s,e;
    char c;
    }a[200001];
    long long ans=0,mi=a[n].e/2;
    int j=0,k=n;
    for (int i=1;i<=mi;i+=0)
    {
        if (a[++j].s<=mi && a[j].e>mi)
        {
            ans-=mi-a[i].s+1;
            if (mi-a[i].s+1>a[i].e-mi)
            {
                while (a[k].e<=n-a[j].e+1 || a[k].s>=n-a[j].s+1)
                {
                    if (a[k].c==a[j].c)
                    {
                        if (a[k].s<=n-a[j].e+1 && a[k].e>n-a[j].s+1)
                        {
                            ans-=a[j].e-a[j].s+1;
                        }
                        else if (a[k].e<=n-a[j].e+1)
                        {
                            ans+=n-a[j].e+1-a[k].e;
                        }
                        else
                        {
                            ans+=a[k].s-n-a[j].s+1;
                        }
                    }
                }
            }
        }
        while (a[k].e<=n-a[j].e+1 || a[k].s>=n-a[j].s+1)
        {
            if (a[k].c==a[j].c)
            {
                if (a[k].s<=n-a[j].e+1 && a[k].e>n-a[j].s+1)
                {
                    ans-=a[j].e-a[j].s+1;
                }
                else if (a[k].e<=n-a[j].e+1)
                {
                    ans+=n-a[j].e+1-a[k].e;
                }
                else
                {
                    ans+=a[k].s-n-a[j].s+1;
                }
            }
        }
        i=a[j].e;
    }
    return;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        if (a1.size()>2*100000000)
        {
            z();
            return 0;
        }
        int l;
        char c;
        cin>>l>>c;
        for (int j=1;j<=l;++j)
        {
            a1+=c;
        }
    }
    for (int i=0;i<a1.size()/2;++i)
    {
        if (a1[i]!=a1[a1.size()-i-1])
        {
            ++ans1;
        }
    }
    cout<<ans1;
    return 0;
}