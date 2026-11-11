#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],c[3005];
map<int,int>mp;
queue<int>q;
queue<int>b;
signed main(void)
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int w=n;
    while(w--)
    {
        memset(c,0,sizeof(c));
        for(int i=n-w;i<=n;i++)
        {
            if(c[a[i]]>0)
            {
                int flag=0;
                while(!q.empty())
                {
                    int x=q.front();
                    if((x!=a[i] && flag==1) || x==a[i])
                    {
                        flag=1;
                        c[x]--;
                    }
                    else b.push(x);
                    q.pop();
                }
            }
            while(!b.empty())
            {
                int x=b.front();
                q.push(x);
                b.pop();
            }
            q.push(a[i]);
            c[a[i]]++;
        }
        while(!q.empty())
        {
            int x=q.front();
            mp[x]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<mp[i]<<" ";
    return 0;
}
