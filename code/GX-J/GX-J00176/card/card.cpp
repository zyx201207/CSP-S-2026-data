#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],p[500001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int b=1;b<=n;b++)
    {
        cin>>a[b];
    }
    for(int b=1;b<=n;b++)
    {
        queue<int> u;
        int s=u.size();
        for(int c=b;c<=n;c++)
        {
            auto it=find(u.front(),u.back(),a[b]);
            if(it==u.back())
            {
                s++;
            }
            else
            {
                s=it;
            }
            u.push(a[b]);
            u.swap(u[s],u[u.size()-1]);
        }
        while(!u.empty())
        {
            p[u.front()]++;
            u.pop();
        }
    }
    for(int b=1;b<=m;b++)
    {
        cout<<p[b]<<" ";
    }
    return 0;
}
