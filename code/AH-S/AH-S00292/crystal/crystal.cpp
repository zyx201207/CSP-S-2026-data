#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,dif1,dif2;
bool f1=1;
int a[N],b[N],tmp_b[N];
inline void sol1()
{
    int t;
    for(int i=1;i<=n;i++)
    {
        t=0;
        for(int j=1;j<=i;j++)
        {
            b[j]=abs(a[j]-a[i]);
            t+=b[j];
            if(t>m)
            {
                cout<<i-1;
                return;
            }
        }
    }
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];/*
        dif1=a[i].em-a[i-1].em;
        if(dif2!=dif1&&i!=1)
        {
            f1=0;
        }*/
    }/*
    if(f1=1)
    {
        sol_special_B();
    }*/
    sol1();
}
//diff crystal.out crystal4.ans
