#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[500005],b[500005],n,m,ans[300005];
deque<int>dq;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int ju=1;ju<=n;ju++)
    {
        memset(a,-1,sizeof a);
        for(int i=ju;i<=n;i++)
        {
            if(a[b[i]]==-1)
            {
                dq.push_back(b[i]);
                a[b[i]]=dq.size();
            }
            else
            {
                int c=1,z=dq.size();
                while(c<=z-a[b[i]]+1&&dq.size())
                {
                    a[dq.back()]=-1;
                    dq.pop_back();
                    c++;
                }
                dq.push_back(b[i]);
                a[b[i]]=dq.size();
            }
        }
        for(int i=1;i<=m;i++) ans[i]+=(a[i]!=-1);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}