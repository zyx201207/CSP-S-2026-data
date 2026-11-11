#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],cnt[M],cntans[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(cnt,0,sizeof(cnt));
        stack <int> s;
        for(int j=i;j<=n;j++)
        {
            if(cnt[a[j]])
            {
                while(s.top()!=a[j])
                {
                    cnt[s.top()]--;
                    s.pop();
                }
            }
            else
            {
                s.push(a[j]);
                cnt[a[j]]++;
            }
        }
        while(!s.empty())
        {
            cntans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cntans[i]<<' ';
    }
    return 0;
}
