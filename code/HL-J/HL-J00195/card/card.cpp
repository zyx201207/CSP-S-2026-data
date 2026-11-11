#include<bits/stdc++.h>
#include<queue>
using namespace std;
int n,m,cnt=1,cntm[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    queue<int>q;//pai
    queue<int>x;//liu
    for(int i=1;i<=n;i++)
    {
        int xxx;
        cin>>xxx;
        q.push(xxx);
    }
    while(!q.empty())
    {
        queue<int>s;
        while(!s.empty())
        {
            if(s.front()==q.front())
            {
                while(!s.empty())
                {
                    x.push(s.front());
                    s.pop();
                }
                break;
            }
            else
            {
                q.push(s.front());
            }
        }
        while(!x.empty())
        {
            if(x.front()==cnt)
            {
                cntm[cnt]++;
            }
            x.pop();
        }
        s.push(q.front());
        cnt++;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cntm[i]<<" ";
    }
    return 0;
}
