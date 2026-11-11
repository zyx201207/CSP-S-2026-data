#include<bits/stdc++.h>
using namespace std;
long long n,m,ans = 0;
long long a[100100];
int jg[5050][3030];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        int x[5050] = {0};
        int t[3030] = {0};
        int k = 1;
        for(int j = i; j <= n; j++)
        {
            if(t[a[j]] == 0)
            {
                t[a[j]] = 1;
                x[k] = a[j];
                k++;
            }
            else
            {
                int tp = 0;
                for(int ij = 1; ij <= k; ij++)
                {
                    if(x[k] = a[j])
                    {
                        tp = 1;
                    }
                    if(tp == 1)
                    {

                        t[x[ij]] = 0;
                        x[ij] = 0;
                        k--;
                    }
                }
                t[a[j]] = 1;
                x[k] = a[j];
                k++;
            }
            for(int ij = 1; ij <= 3030; ij++)
            {
                if(t[ij] == 1)
                {
                    jg[i][ij] = 1;
                }
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        long long sum = 0;
        for(int j = 1; j <= n; j++)
        {
            if(jg[j][i] == 1)
            {
                sum++;
            }
        }
        cout << sum << " ";
    }
    return 0;
}
//Trick||Treat!
