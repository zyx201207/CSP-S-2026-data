#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int island[200005];
vector<int> vec[5005];
vector<int> answer;
int minn=99999999;
void dfs(int i,int j,int ans)
{
    if(i>j)return;
    if(i==j)
    {
        answer.push_back(ans);
        minn=min(minn,ans);
        return;
    }
    for(int k=0;k<vec[i].size();k++)
    {
        if(vec[i][k]>j)break;
        dfs(vec[i][k],j,ans+1);
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;c=read();t=read();
    while(t--)
    {
        int n,d;n=read();d=read();
        memset(island,0,sizeof(island));
        for(int i=1;i<=n;i++)island[i]=read();
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(island[j]-island[i]>d)break;
                vec[i].push_back(j);
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                answer.clear();minn=99999999;
                dfs(i,j,0);int ans=0;bool t=true;
                for(int k=0;k<answer.size();k++)
                {
                    if(answer[k]==minn)
                    {
                        ans++;
                    }
                    if(ans>2)
                    {
                       t=false; break;
                    }
                }
                if(t&&ans==2)
                {
                    sum++;
                }
            }
        }
        cout<<sum;
        if(t>=1)cout<<endl;
    }
    return 0;
}
