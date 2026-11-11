#include<iostream>
using namespace std;
long long a[500005];
int n;
long long m;
int ilw(int w)
{
    w*=2;
    for(int i=1;i<=50000;i++)
    {
        if(i*(i+1)>=m)
            return i;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long d=a[2]-a[1];
    m/=d;
    if(n*(n+1)<=m)
    {
        cout<<n;
    }
    else
    {
        cout<<ilw(m)+1;
    }
    return 0;
}
//di yi ti jiu bu hui wo hai you jiu m...
//wo xiang bai lan
//Chinese can fly jian cheng ???
