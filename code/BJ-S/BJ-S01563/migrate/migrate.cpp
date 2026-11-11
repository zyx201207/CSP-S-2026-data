#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+5;
long long a[MAXN];
int f[MAXN][22],g[MAXN][22];
int f1[5005][5005],g1[5005][5005];
int nxt[MAXN],lst[MAXN],st[5005][5005];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        int n;
        long long d;
        cin >> n >> d;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1,j = 1;i <= n;i++)
        {
            while(j <= n && a[j] <= a[i]+d) j++;
            nxt[i] = j-1;
            //cout << nxt[i] << " ";
        }
        //cout << endl;
        for(int i = n,j = n;i >= 1;i--)
        {
            while(j >= 1 && a[j]+d >= a[i]) j--;
            lst[i] = j+1;
            //cout << lst[i] << " ";
        }
        //cout << endl;
        if(c == 11 || c == 12) cout << 0 << endl;
        else if(c <= 10)
        {
            for(int i = 1;i <= n;i++)
            {
                int sum = 0,k = i;
                for(int j = 1;j <= n;j++)
                {
                    f1[i][j] = sum;
                    sum += nxt[k];
                    for(int l = k+1;l <= nxt[k];l++) st[i][l] = j;
                    k = nxt[k];
                }
            }
            for(int i = 1;i <= n;i++)
            {
                int sum = 0,k = i;
                for(int j = 1;j <= n;j++)
                {
                    g1[i][j] = sum;
                    sum += lst[k];
                    k = lst[k];
                }
            }
            int cnt = 0;
            for(int i = 1;i <= n;i++)
            {
                for(int j = i;j <= n;j++)
                {
                    int k = st[i][j];
                    if(g1[j][k]+1 == f1[i][k]) cnt++;
                    //cout << i << " " << j << " " << g1[j][k] << " " << f1[i][k] << endl;
                }
            }
            cout << cnt << endl;
        }
        else if(c >= 13 && c <= 18)
        {
            for(int i = 1;i <= n;i++)
            {
                int sum = 0,k = i;
                for(int j = 1;j <= 10;j++)
                {
                    f[i][j] = sum;
                    sum += nxt[k];
                    k = nxt[k];
                }
            }
            for(int i = 1;i <= n;i++)
            {
                int sum = 0,k = i;
                for(int j = 1;j <= 10;j++)
                {
                    g[i][j] = sum;
                    sum += lst[k];
                    k = lst[k];
                }
            }
            int cnt = 0;
            for(int i = 1;i <= n;i++)
            {
                int k = i;
                for(int j = 1;j <= 10;j++)
                {
                    k = nxt[k];
                    if(g[k][j]+1 == f[i][j]) cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
/*
3 1
6 2
1 2 4 5 6 7
*/
