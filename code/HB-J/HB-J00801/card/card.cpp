#include<bits/stdc++.h>
using namespace std;
int a[500005],t[300005];
bool vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    deque<int>p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(!vis[a[j]]) {p.push_back(a[j]);vis[a[j]]=true;}
            else
            {
                while(p.back()!=a[j])
                {
                    int f=p.back();
                    vis[f]=false;
                    p.pop_back();
                }
            }
        }
                for(int k=1;k<=p.size();k++)
                {
                    int s=p.back();
                    p.pop_back();
                    t[s]++;
                    p.push_front(s);
                }
    }
    for(int i=1;i<=m;i++)
    {
        if(t[i]) cout<<t[i]<<" ";
    }
    return 0;
}