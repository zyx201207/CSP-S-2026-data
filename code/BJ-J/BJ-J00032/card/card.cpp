#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[500005],cnt[500005];
queue<int> q;
void check(int x)
{
    int siz=q.size(),f=1;
    while(siz--)
    {
        if(q.front()==x)
        {
            f=0;
        }
        if(f)
        {
            q.push(q.front());
        }
        q.pop();
    }
}
void play(int x)
{
    for(int i=x;i<=n;i++)
    {
        check(a[i]);
        q.push(a[i]);
    }
    int siz=q.size();
    while(siz--)
    {
        cnt[q.front()]++;
        q.pop();
    }
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        play(i);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
    return 0;
}