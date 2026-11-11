#include<bits/stdc++.h>
using namespace std;
long long a[1000006],ans[1000006];
int b[1000006];
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
        stack<long long> s;
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++)
        {
            stack<long long> q;
            if(b[a[j]])
            {
                while(!s.empty())
                {
                    if(s.top()!=a[j])
                    {
                        b[s.top()]--;
                        s.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }else{
                b[a[j]]++;
                s.push(a[j]);
            }

        }
        while(!s.empty())
        {
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
}
