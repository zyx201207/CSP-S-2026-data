#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll val,ppcnt;
}a[200005];
ll n,m,ans;
node tp;
void tobin(ll pos)
{
    ll x=a[pos].val,sum=0;
    while(x>0)
    {
        if(x%2)sum++;
        x/=2;
    }
    a[pos].ppcnt=sum;
}
bool cmp1(node x,node y)
{
    if(x.ppcnt!=y.ppcnt)return x.ppcnt>y.ppcnt;
    else return x.val>y.val;
}
bool cmp2(node x,node y)
{
    return (x.val&tp.val)>(y.val&tp.val);
}
bool cmp3(node x,node y)
{
    return x.val>y.val;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].val;
        tobin(i);
    }
    if(m==1)
    {
        sort(a+1,a+n+1,cmp3);
        cout<<a[1].val;
        return 0;
    }
    sort(a+1,a+n+1,cmp1);
    tp=a[1];
    ans=a[1].val;
    sort(a+2,a+n+1,cmp2);
    for(int i=2;i<=m;i++)
    {
        //for(int j=28;j<=31;j++)cout<<a[i].bin[j];
        //cout<<endl;
        ans=ans&a[i].val;
    }
    cout<<ans;
    return 0;
}
