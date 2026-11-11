#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
bool book[N];
long long a[N],maxn=LONG_LONG_MIN;
void dfs(int x,int count,long long cnt)
{
    if(x==n+1)
    {
        if(cnt>maxn && count==m+1)
        {
            maxn=cnt;
        }
        return ;
    }
    for(int i=x;i<=n;i++)
    {
        if(count == 0)
        {
            cnt=a[i];
        }
        dfs(x+1,count+1,cnt&a[i]);
        dfs(x+1,count,cnt);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    dfs(1,0,0);
    cout << maxn;
    return 0;
}
