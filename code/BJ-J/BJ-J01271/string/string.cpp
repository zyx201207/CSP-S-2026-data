#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long k;
    char s;
}a[100000100];
char c[100000100],d[100000100];
long long n,z1,z2,oq;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].k>>a[i].s;
        for(int j=1;j<=a[i].k;j++)
            c[++oq]=a[i].s;
        z1+=a[i].k;
    }
    long long op=0,o=0;
    for(int i=oq;i>=1;i--)
    {
        d[++op]=c[i];
    }
    for(int i=1;i<=oq;i++)
    {
        if(d[i]!=c[i]) o++;
    }
    cout<<o/2;
    return 0;
}
