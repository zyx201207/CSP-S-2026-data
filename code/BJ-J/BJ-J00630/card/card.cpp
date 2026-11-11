#include<iostream>
#include<stack>
using namespace std;
int a[500005],b[300005],cnt[300005];
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
        stack<int> s;
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]]==0)
            {
                s.push(a[j]);
            }
            else
            {
                int t=j-b[a[j]];
                for(int k=1;k<=t;k++)
                {
                    s.pop();
                }
                s.push(a[j]);
            }
            b[a[j]]=j;
        }
        while(!s.empty())
        {
            cnt[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
