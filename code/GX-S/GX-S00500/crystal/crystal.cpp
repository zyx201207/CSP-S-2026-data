#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],b[500005];
long long m;
//int f(long long x,long long y,long long mm)
//{
//    if(y%(x)==0)return x;
//    else f(x+1,y,mm);
//}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    b[0]=0;
    for(int i=1;i<=n;i++)
    {
        b[i]+=b[i-1]+a[i];
    }
    for(int i=n;i>=1;i--)
    {
//        a[i]=f(a[i],b[i]+m,m);
//        cout <<a[i]<<" ";
        if((b[i]+m)>=a[i]*i)
        {
            cout <<i;
            return 0;
        }

    }
    return 0;
}
