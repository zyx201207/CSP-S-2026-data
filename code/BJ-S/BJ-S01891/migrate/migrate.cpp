#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000005];
struct node
{
    int num;
    int step;
};
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T,c;
    cin>>c>>T;
    while(T--)
    {
        int n,i,j,k;
        ll d;
        cin>>n>>d;
        for(i=1;i<=n;i++)
            cin>>a[i];
        if(c==11||c==12)
        {
            int ch=a[2]-a[1];
            d/=ch;
            if(d==1)
                cout<<0<<"\n";
            else
                cout<<max(0ll,n-(d*2)+1)<<"\n";
        }
        else
        {
            vector<int> vt[5005];
            for(i=1;i<=n;i++)
            {
                for(j=i+1;j<=n;j++)
                {
                    if(a[i]>=a[j]-d)
                    {
                        vt[i].push_back(j);
                    }
                }
            }
            queue<node> q;
            int ans=0;
            for(i=2;i<=n;i++)
            {
                for(j=1;j<i&&a[j]<a[i]-d;j++)
                {
                    q.push({j,0});
                    int cnt=0,st=2e9;
                    while(q.size())
                    {
                        node cur=q.front();
                        q.pop();
                        if(cur.num==i)
                        {
                            if(cur.step<=st)
                            {
                                cnt++;
                                st=cur.step;
                            }
                            continue;
                        }
                        for(k=0;k<vt[cur.num].size();k++)
                        {
                            int nxt=vt[cur.num][k],s=cur.step;
                            q.push({nxt,s+1});
                        }
                    }
                    if(cnt==2)
                        ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
