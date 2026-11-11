#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int len;
    int l,r;
    char c;
};
vector<node> a(200005);
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,len=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].len>>a[i].c;
        a[i].l=len;
        len+=a[i].len;
        a[i].r=len;
    }
    long long cnt=0;
    for(int i=1,j=n;i<j;)
    {
        if(a[i].len>a[j].len)
        {
            if(a[i].c!=a[j].c) cnt+=a[j].len;
            a[i].len-=a[j].len;
            a[i].l=a[i].r+1-a[i].len;
            j--;
        }
        else if(a[i].len==a[j].len)
        {
            if(a[i].c!=a[j].c) cnt+=a[i].len;
            i++,j--;
        }
        else if(a[i].len<a[j].len)
        {
            if(a[i].c!=a[j].c) cnt+=a[i].len;
            a[j].len-=a[i].len;
            a[j].r=a[j].len+a[j].l-1;
            i++;
        }
    }
    cout<<cnt;
    return 0;
}
