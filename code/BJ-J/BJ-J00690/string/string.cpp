#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt,ans=0,flag;
struct str{
    int m;
    char s;
}a[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].m;
        cin>>a[i].s;
        cnt+=a[i].m;
    }
    cnt/=2;
    int l=1,r=n,cnt1=0;
    while(l<r)
    {
        cnt1+=min(a[l].m,a[r].m);
        if(a[l].s!=a[r].s)
        {
            ans+=min(a[l].m,a[r].m);
        }
        int temp=min(a[l].m,a[r].m);
        a[l].m-=temp;
        a[r].m-=temp;
        if(a[l].m<=0)
        {
            l++;
        }
        if(a[r].m<=0)
        {
            r--;
        }
        if(cnt1>=cnt)
        {
            break;
        }
    }
    cout<<ans;
}