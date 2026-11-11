#include<bits/stdc++.h>
using namespace std;
/*                          \                    _____
        |  |           _____________      |     /     \      |           |
  ______|  |______        _______         |    /       \     |      _____|_____
        |  |              |     |         |   |         |    |     |     |     |
       _|  |              |_____|         |   |         |    |     |_____|_____|
     _/ |  |\_               |            |   |         |    |           |
   _/   |  |   \_        /   |   \        |   |         |    |           |
  /     |  |     \_     /  \ |    \       |    \       /     |           |
        |  |                \|            |     \_____/      |           |         */
int n,m,a,cnt[200005],ans;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        a++;
        cnt[i]=log(a)/log(2)-1;
    }
    sort(cnt+1,cnt+1+n,cmp);
    for(int i=1;i<=cnt[m-1];i++) ans=ans*2+1;
    cout<<ans;
    return 0;
}
