#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[N],c[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ma;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    long long x=1;
    while(x<a[1])
    {
        x*=2;
    }
    x/=2;
    int h=n,p=0;
    bool f=0;
    while(h==m&&f==0)
    {
        int s=h;
        p=0;
        for(int i=1;i<=s;i++)
        {
            if(c[i]>x)
            {
                h--;
                p++;
            }
            if(h==m)
            {
                f=1;
                break;
            }
            c[i]-=x;
        }
        if(p<m)
            sort(a+1,a+n+1,greater<int>());
        x/=2;
    }
    for(int i=1;i<=m;i++)
    {
        a[1]&=a[i];
    }
    cout<<a[1];
    return 0;
}

