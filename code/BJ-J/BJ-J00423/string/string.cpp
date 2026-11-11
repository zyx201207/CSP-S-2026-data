#include<bits/stdc++.h>
using namespace std;
struct str{
    long long a;
    char c;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    str a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].c;
    long long p1=1,p2=n;
    while(p1<p2)
    {
        if(a[p1].c!=a[p2].c)ans+=min(a[p1].a,a[p2].a);
        if(a[p1].a<a[p2].a)a[p2].a-=a[p1].a,p1++;
        else if(a[p1].a>a[p2].a)a[p1].a-=a[p2].a,p2--;
        else p1++,p2--;
    }
    cout<<ans;
    return 0;
}
