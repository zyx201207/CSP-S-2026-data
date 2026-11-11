#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
long long b[300005];
long long c,d,e;
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>c>>d;
for(long long i=1;i<=c;i++)
{
    cin>>a[i];
    cout<<a[i]-a[i]/c+3;
}
return 0;
}
