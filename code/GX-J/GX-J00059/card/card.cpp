#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500010], lis[500010], fir[500010], ans[300010];
void init()
{
    for(int i = 1; i <= n; i++)
    {
        fir[i] = 0;
        lis[i-1] = i;
    }

}
int main()
{

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        lis[i-1] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(fir[a[j]] == 0) fir[a[j]] = j;
            else lis[fir[a[j]]-1] = j;
        }
        int id = i-1;
        while(1)
        {
            ans[a[lis[id]]]++;
            if(id == n) break;
            id = lis[id];
        }
        init();
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
