#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool flag[300005];
stack<int>s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            s.push(a[j]);
            if(flag[a[j]])
            {
                flag[a[j]]=false;
                s.pop();
                while(s.top()!=a[j])
                {
                    flag[s.top()]=false;
                    s.pop();
                }
            }
            else
                flag[a[j]]=true;
        }
        while(!s.empty())
        {
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}