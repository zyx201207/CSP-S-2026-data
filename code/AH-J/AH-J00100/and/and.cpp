#include <bits/stdc++.h>
using namespace std;
int n, m, maxx = 0, t = 1;
int num[200005];
int dfs(int x, int maxxx){
    t++;
    for(int i = x+1;i < n;i++)
    {
        maxxx = max(maxxx, (num[x]&num[i]));
        if(t == m){
            maxx = max(maxx, maxxx);
        }
        else{
            dfs(i, maxxx);
            t--;
        }
        cout << maxx << "";
    }
    return maxx;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> num[i];
    }
    if(m == 1)
    {
        int big = 0;
        for(int i = 0;i < n;i++)
        {
            big = max(big, num[i]);
        }
        cout << big;
        return 0;
    }
    else{
        cout << dfs(0, num[0]);
    }
    return 0;
}
