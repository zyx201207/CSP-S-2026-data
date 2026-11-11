#include<bits/stdc++.h>
using namespace std;
long long t,x[200005];
long long c,n,m,ans;
long long flag[200005],cnt[200005];
vector<long long> v[200005];
struct node{
    long long v,w;
};
void bfs(long long tp)
{
    memset(flag,false,sizeof(flag));
    memset(cnt,0,sizeof(cnt));
    queue<node> q;
    q.push({tp,0});
    flag[tp]=true;
    while(!q.empty())
    {
        //cout<<"qtqt";
        node qt =q.front();
        q.pop(); 
        for(long long it : v[qt.v])
        {
            //cout<<it<<" "<<qt.w+1<<" ! ";
            if(!flag[it])
            {
                q.push({it,qt.w+1});
                cnt[it]=qt.w+1;
                flag[it]=1;
            }
            else
            {
                if(cnt[it]==qt.w+1)
                {
                    flag[it]++;
                    //cout<<"??"<<it<<"??";
                }
            }
        }
    }
    for(long long i = 1;i<=n;i++)
    {
        if(flag[i]==2 && i>tp)
        {
            ans++;
            //cout<<i<<" "<<cnt[i]<<" || ";
        } 

    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        for(long long i = 1;i<=n;i++)
        {
            v[i].clear();
        }
        cin>>n>>m;
        for(long long i = 1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(long long i = 1;i<=n;i++)
        {
            for(long long j = i+1;j<=n;j++)
            {
                if(x[i]+m>=x[j])
                {
                    v[i].push_back(j);
                    //v[j].push_back(i);
                }
                else
                {
                    break ;
                }
            }
        }
        for(long long i = 1;i<=n;i++)
        {
            bfs(i);
            //cout<<i<<endl;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}