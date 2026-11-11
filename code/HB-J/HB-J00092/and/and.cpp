#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
struct node
{
    int x;
    int cnt;
}a[214514];
void count0(int id,int x)
{
    int k=0;
    while(x)
    {
        x&=x-1;
        k++;
    }
    a[id].cnt=k;
}
bool cmp(node a,node b)
{
    if(a.cnt!=b.cnt)return a.cnt>b.cnt;
    else return a.x>b.x;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i].x,count0(i,a[i].x);
    sort(a+1,a+1+n,cmp);
    int ans=a[1].x;
    for(int i=2;i<=m;i++)
        ans&=a[i].x;
    cout<<ans;
}
