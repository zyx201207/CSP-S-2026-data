#include<bits/stdc++.h>
using namespace std;
int a[500005];
int h[300005];
int ans[300005];
stack<int> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
       cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        //cout<<"\n---------------------------\n";
        for(int j=1;j<=m;j++) h[j]=0;
        for(int j=i;j<=n;j++)
        {
            if(!h[a[j]]) h[a[j]]++,s.push(a[j]);
            else
            {
                while(s.top()!=a[j])
                {
                    h[s.top()]=0;
                    s.pop();

                }
            }
        }
        while(s.size())
        {
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
