#include<bits/stdc++.h>
using namespace std;
int T,n,d,a[2000005],mark[2000005][2];
struct node
{
    int x,step;
};
queue<node> q;
inline void bfs()
{
    while(!q.empty())
    {
        node t=q.front();
        q.pop();
        int dx=a[t.x]+d;
        for(int i=t.x+1;i<=n;i++)
        {
            if(dx<a[i])break;
            if(mark[i][0]==0)mark[i][0]=1,mark[i][1]=t.step+1;
            else
            {
                if(t.step+1==mark[i][1])mark[i][0]++;
                else if(t.step+1<mark[i][1])mark[i][0]=1,mark[i][1]=t.step+1;
            }
            q.push(node{i,t.step+1});
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>T>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)cin>>a[j];
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            q.push(node{j,0});
            bfs();
            for(int k=j+1;k<=n;k++)if(mark[k][0]==2)cnt++;
            memset(mark,0,sizeof(mark));
        }
        cout<<cnt<<endl;
    }
    return 0;
}
