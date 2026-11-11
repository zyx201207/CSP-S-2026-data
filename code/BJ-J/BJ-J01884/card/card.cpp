#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#define fin freopen("card.in","r",stdin);
#define fout freopen("card.out","w",stdout);
using namespace std;
struct edge
{
    int v,w;//a[now]=a[v]+(w)
    edge() {v=w=0;}
    edge(int vv,int ww) {v=vv,w=ww;}
};
int n,m;
int a[500005],ans[500005];
int toright[500005],lst[500005];
edge es[500005];
int ind[500005];
queue<int> q;
int multiplier[500005];
int main()
{
    fin
    fout
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=n;i>=1;i--)
    {
        if(lst[a[i]])
            toright[i]=lst[a[i]];
        else
            lst[a[i]]=i;
    }
    for(int i=n;i>=1;i--)
    {
        if(toright[i])
        {
            es[i]=edge(toright[i],0);
            ind[toright[i]]++;
        }
        else
        {
            es[i]=edge(i+1,a[i]);
            ind[i+1]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        multiplier[i]=1;
        if(!ind[i])
            q.push(i);
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(es[x].w)
        {
            ans[es[x].w]+=multiplier[x];
            //cout << "at " << x << ": added " << multiplier[x] << " to ans[" << es[x].w << "]\n";
        }
        if(x<n)
        {
            multiplier[es[x].v]+=multiplier[x];
            if(--ind[es[x].v]==0)
                q.push(es[x].v);
        }
    }
    /*
    for(int i=1;i<=n;i++)
        cout << es[i].v << ' ' << es[i].w << endl;
    for(int i=1;i<=n;i++)
        cout << multiplier[i] << ' ';
    cout << endl;
    //*/
    for(int i=1;i<=m;i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
