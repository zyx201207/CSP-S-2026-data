#include<bits/stdc++.h>
using namespace std;
struct node{int num,start;};
int n,m,a[500010],cnt[500010];
bool flag[500010];
deque<node> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int t=1;t<=n;t++)
    {
        memset(flag,0,sizeof flag);
        for(int i=t;i<=n;i++)
        {
            if(flag[a[i]])
            {
                while(q.back().num!=a[i])
                {
                    flag[q.back().num]=0;
                    q.pop_back();
                }
            }
            else q.push_back({a[i],i});
            flag[a[i]]=1;
        }
        while(!q.empty()){cnt[q.back().num]++;q.pop_back();}
    }
    for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
    return 0;
}
