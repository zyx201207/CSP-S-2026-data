#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
    long long a;
    char c;
}a[200010];
long long sum,ans;
long long you,zuo;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a>>a[i].c;
        sum+=a[i].a;
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    int l=1,r=n;
    zuo=a[1].a,you=a[n].a;
    while(l<=r)
    {
        if(zuo<=you)
        {
            if(a[l].c!=a[r].c)ans+=zuo;
            you-=zuo;
            zuo=a[l+1].a,l++;
        }
        else
        {
            if(a[l].c!=a[r].c)ans+=you;
            zuo-=you;
            you=a[r-1].a,r--;
        }

    }
    cout<<ans;
    return 0;
}
