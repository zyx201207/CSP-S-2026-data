#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m;
int a[N];
bool flag[N];
int ans[N];
stack<int> S;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        memset(flag,0,sizeof flag);
        for(int j = i;j <= n;j++)
        {
            if(flag[a[j]])
            {
                while(S.top() != a[j]) flag[S.top()] = 0,S.pop();
                S.pop();
            }
            S.push(a[j]);
            flag[a[j]] = 1;
        }
        while(S.size())
        {
            ans[S.top()]++;
            S.pop();
        }
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << " ";
    return 0;
}
