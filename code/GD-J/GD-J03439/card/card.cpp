#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ans[300010];
int c[500010];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
        c[i] = a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        int b[500010] = {0};
        for(int j = i;j<=n;j++)
        {
            if(b[a[j]]==0)
            {
                ans[a[j]]++;
                b[a[j]] = j;
            }
            else
            {
                b[a[j]] = j;
                for(int k = b[a[j]+1];k<=j-1;k++)
                {
                    ans[a[k]]--;
                    b[a[k]] = 0;
                    a[k] = 0;
                }
            }
        }
        for(int i = 1;i<=n;i++)
        {
            if(a[i]==0)
            {
                a[i] = c[i];
            }
        }
    }
    for(int i = 1;i<=m;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
