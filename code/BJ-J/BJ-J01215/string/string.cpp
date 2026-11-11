#include<iostream>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    long long n,l,s=0,m=1,r=0;
    string p,a[200005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>p;
        r+=l;
        for(long long j=1;j<=l;j++)
        {
            a[m]=p;
            m++;
        }
    }
    for(int i=1;i<=r/2;i++)
    {
        if(a[i]!=a[r+1-i]);
            s++;
    }
    cout<<s;
    freopen("string.out","w",stdout);
    return 0;
}
