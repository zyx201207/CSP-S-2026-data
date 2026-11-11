#include <iostream>
#include <vector>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int ans[N];
int to[N];
int last[M];
int n, m;
int a[N];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        to[i]=-1;
    for (int i=1;i<=m;i++)
        last[i]=-1;
    for (int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        a[i]=k;
        if (last[k]!=-1)
            to[last[k]]=i;
        last[k]=i;
    }
    for (int i=1;i<=n;i++)
    {
        int tmp[M]={0};
        for (int j=i;j<=n;j=j)
        {
            if (to[j]==-1)
            {
                tmp[a[j]]=1;
                j++;
                continue;
            }
            j=to[j];
        }
        for (int i=1;i<=m;i++)
            ans[i]+=tmp[i];
    }
    for (int i=1;i<=m;i++)
        cout << ans[i] << " ";
    return 0;
}