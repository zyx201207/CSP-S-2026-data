#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],c,q,d,x,y,a1,a2,a3;
bool f(int a,int b)
{
return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c+=a[i];
    }
    sort(a+1,a+1+n,f);
    if(m==1)
    {
        cout<<a[1];
        return 0;
    }
        cout<<a[n/2+1];
        return 0;
    return 0;
}
