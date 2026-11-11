#include<iostream>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
bool ch[N];
int maxn;
void dfs(int cur)
{
    if(cur>n)
    {
        int cmp=0;
        bool flag=1;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(ch[i])
            {
                cnt++;
                if(cmp==0)
                {
                    cmp=a[i];
                }
                else
                {
                    cmp&=a[i];
                }
            }
        }
        if(cnt==m)
        {
            maxn=max(maxn,cmp);
        }
        return;
    }
    ch[cur]=1;
    dfs(cur+1);
    ch[cur]=0;
    dfs(cur+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    dfs(1);
    cout <<maxn;
    return 0;
}//暴力
