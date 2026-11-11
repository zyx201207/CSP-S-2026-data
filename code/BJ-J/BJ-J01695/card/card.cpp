#include <bits/stdc++.h>
#include <string>
using namespace std;

const int MAXN = 500005;
int a[MAXN];
int gameevery[MAXN];
int dict[MAXN]; // the i-points card appear for dict[i] time

//A
int cntt[MAXN];
int summ[MAXN]; //qianzhuihe

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);


    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    //teshuxingzhi A
    bool aflag = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] > a[i]) aflag = 0;
    }

    if (aflag)
    {
        for (int i = 1; i <= n; i++)
        {
            cntt[a[i]]++;
        }
        for (int i = 1; i <= m; i++)
        {
            summ[i] = cntt[i] + summ[i - 1];
        }

        for (int i = 1; i <= m; i++)
        {
            cout << summ[i] << " ";
        }
        return 0;
    }

    //moni 1-6
    for (int i = 1; i <= n; i++) //di i ju you xi
    {
        memset(gameevery, 0, sizeof(gameevery));

        for (int j = i; j <= n; j++)  //dachu a[j]
        {
            for (int k = i; k < j; k++)// bianli qianmian you meiyou
            {
                if (gameevery[k] == a[j])
                {
                    for (int l = k; l < j; l++) //shanchu
                    {
                        gameevery[l] = 0;
                    }
                }
            }
            gameevery[j] = a[j];
        }

        for (int i = 1; i <= n; i++)
        {
            //cout << gameevery[i] << " ";
            dict[gameevery[i]]++;
        }
        //cout << endl;
    }


    for (int i = 1; i <= m; i++)
    {
        cout << dict[i] << " ";
    }
    return 0;
}
