#include <bits/stdc++.h>
using namespace std;
const int N=3*1e5+100;
bool check[N];
stack <int> q;
int d[N],ans[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()) q.pop();
        for(int j=i;j<=n;j++)
        {
            if(check[d[j]])
            {
                while(!q.empty() && q.top()!=d[j])
                {
                    check[q.top()]=false;
                    q.pop();
                }
                q.pop();
            }
            q.push(d[j]),check[d[j]]=true;
        }
        for(int j=1;j<=m;j++)
            if(check[j]) ans[j]++,check[j]=false;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}