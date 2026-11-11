#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int CNT,C,sum,pos,p,c,t,n,d,Pos,flag;cin >> c >> t;
    if (c <= 2)
    {
        for (int i = 0;i < t;i++)
        {
            cin >> n >> d;int a[n];for (int j = 0;j < n;j++){cin >> a[j];}
            sort(a,a + n);int NSP[n][n],LSP[n][n];
            for (int r1 = 0;r1 < n;r1++)
            {
                for (int r2 = 0;r2 < n;r2++)
                {
                    NSP[r1][r2] = 0;
                    LSP[r1][r2] = 1000000;
                }
            }
            p = 1;for (int j = 0;j < n;j++){p = p + p;}
            for (int j = 0;j < p;j++)
            {
                int s[n];sum = 0;
                pos = 0;for (int k = 0;k < n;k++){s[k] = 0;}
                C = j;while (C){s[pos] = C % 2;C = C / 2;pos++;}
                for (int k = 0;k < n;k++){sum += s[k];}
                int S[sum];Pos = 0;
                for (int k = 0;k < n;k++)
                {
                    if (s[k] == 1){S[Pos] = k;Pos++;}
                }
                flag = 1;
                for (int k = 0;k < sum - 1;k++)
                {
                    if (a[S[k + 1]] - a[S[k]] > d){flag = 0;}
                }
                if (flag == 1 && sum >= 2)
                {
                    if (LSP[S[0]][S[sum - 1]] > sum)
                    {
                        NSP[S[0]][S[sum - 1]] = 1;
                        LSP[S[0]][S[sum - 1]] = sum;
                    }
                    else if (LSP[S[0]][S[sum - 1]] == sum)
                    {
                        NSP[S[0]][S[sum - 1]] += 1;
                    }
                }
            }
            CNT = 0;
            for (int r1 = 0;r1 < n;r1++)
            {
                for (int r2 = 0;r2 < n;r2++)
                {
                    if (NSP[r1][r2] == 2){CNT++;}
                }
            }
            cout << CNT << endl;
        }
    }
    return 0;
}