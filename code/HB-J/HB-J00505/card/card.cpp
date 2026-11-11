#include <bits/stdc++.h>
using namespace std;
int n,m;
int fp[500001];
int c[300001];
stack <int> s;
int book[300001];
bool fa=true;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>fp[i];
        if(fp[i]<fp[i-1])fa=false;
    }
    if(fa)
    {
        for(int i = 1;i<=m;i++) cout<<i<<" ";
        return 0;
    }
    for(int k = 0;k<n;k++)
    {
        for(int i = k+1;i<=n;i++)
        {
            if(book[fp[i]]==0)
            {
                s.push(fp[i]);
                book[fp[i]]=1;
            }
            else
            {
                while(s.top()!=fp[i])
                {
                    book[s.top()]=0;
                    s.pop();
                }
            }
        }
        while(!s.empty())
        {
            int t=s.top();
            s.pop();
            book[t]=0;
            c[t]++;
        }
    }
    for(int i = 1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}
