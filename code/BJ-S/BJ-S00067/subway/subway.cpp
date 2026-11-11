#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int w[N],k[500],a[500][N],t[500][N];
bool change[N];
struct station
{
    vector<int> line;
    int id;
}st[N];
int main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++)
        {
            scanf("%d%d",&a[i][j],&t[i][j]);
            st[j].line.push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int l=1;l<=k[i];l++)
                for(int r=1;r<=k[j];r++)
                    if(a[i][l]==a[j][r])
                        change[a[i][l]]=true;
        }
    }

    while(q--)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        long long ans=0;
        ans+=w[s];
        ans+=w[t];
        int l;
        for(int i=0;i<st[s].line.size();i++)
            for(int j=0;j<st[t].line.size();j++)
                if(st[s].line[i]==st[t].line[j])
                    l=st[s].line[i];
        int x;
        for(int i=1;i<=k[l];i++)
        {
            if(change[i])
            {
                x=i;
                break;
            }
        }

        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
