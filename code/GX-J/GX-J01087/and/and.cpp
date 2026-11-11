#include<bits/stdc++.h>
using namespace std;
long long n,m,z,k;
struct ss
{
    long long a;
    long long b;
}x[200005];
bool cmp(ss a, ss b)
{
    if(a.b>=m&&b.b>=m) return a.a>b.a;
    return a.b>b.b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    z=0;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        x[k].a=k;
        x[k].b++;
        z=max(z,k);
    }
    if(m==1) cout<<z;
    else
    {
        sort(x+1,x+z+1,cmp);
        cout<<x[1].a;
    }
    return 0;
}
