//GZ-S00211，卿可玥，贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int h[m][m];
    memset(h,0x3f,sizeof(h));
    vector<int>l[m+1];
    int w[m+1];
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int k[n];
    vector<int>a[n];
    vector<int>t[n];
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
        for(int j=0;j<k[i];j++)
        {
            int aa,bb;
            cin>>aa>>bb;
            a[i].push_back(aa);
            t[i].push_back(bb);
            if(j==0)
            {
                continue;
            }
            if(j==k[i]-1)
            {
                h[a[i][0]][a[i][j]]=min(h[a[i][0]][a[i][j]],t[i][0]+t[i][j]);
                h[a[i][j]][a[i][0]]=h[a[i][0]][a[i][j]];
                l[a[i][j]].push_back(a[i][0]);
                l[a[i][0]].push_back(a[i][j]);
            }
            h[a[i][j]][a[i][j-1]]=min(h[a[i][j]][a[i][j-1]],t[i][j]+t[i][j-1]);
            h[a[i][j-1]][a[i][j]]=h[a[i][j]][a[i][j-1]];
            l[a[i][j]].push_back(a[i][j-1]);
            l[a[i][j-1]].push_back(a[i][j]);
        }
    }
    int x[q],y[q];
    queue<int>st;
    queue<int>ed;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<l[i].size();j++)
        {
            st.push(i);
            ed.push(l[i][j]);
        }
    }
    while(st.size()>0)
    {
        for(int i=0;i<l[ed.front()].size();i++)
        {
            int u=h[st.front()][ed.front()]+h[ed.front()][l[ed.front()][i]];
            if(u<h[st.front()][l[ed.front()][i]])
            {
                h[st.front()][l[ed.front()][i]]=u;
                st.push(st.front());
                ed.push(l[ed.front()][i]);
            }
        }
        st.pop();
        ed.pop();
    }
    for(int i=0;i<q;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<q;i++)
    {
        cout<<h[x[i]][y[i]]+w[x[i]]+w[y[i]]<<endl;
    }
    return 0;
}
