#include <iostream>
#include <cstring>

using namespace std;
int n, m, p;
int a[500005] = {};
int ans[300005] = {};
int game[500005] = {};
int gamenum[300005] = {};
bool gamef[500005] = {};

void work(int x)
{
    memset(game, 0, sizeof(game));
    memset(gamenum, 0, sizeof(gamenum));
    memset(gamef, 1, sizeof(gamef));
    p = 1;
    for (int i = x; i <= n; i ++)
    {
        game[p] = a[i];
        if(gamenum[a[i]] != 0 && gamef[gamenum[a[i]]] == 1)
        {
            for (int j = gamenum[a[i]]; j < p; j ++)
            {
                gamef[j] = 0;
            }
            gamenum[a[i]] = p;
        }
        else
        {
            gamenum[a[i]] = p;
        }
        p ++;
    }
    for (int i = 1; i <= p; i ++)
    {
        ans[game[i]] += gamef[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        work(i);
    }
    for (int i = 1; i <= m; i ++)
    {
        cout << ans[i] << " ";
    }
	return 0;
}
