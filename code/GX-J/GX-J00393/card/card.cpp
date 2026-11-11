#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005];
int num[200005], ansnum[200005];
int pos[500005];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    //read
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }


    for (int j=1;j<=n;j++)
    {
        int na[500005];
        memset(num,0,sizeof num);
        memset(pos,0,sizeof pos);
        memset(na,0,sizeof na);
        for (int i=j;i<=n;i++)
        {
            na[i] = a[i];

        }

        for (int i=j;i<=n;i++)
        {
            num[na[i]]++;
            if (num[na[i]] > 1)
            {
                for (int k=pos[na[i]]; k<i;k++)
                    na[k] = 0;
                num[na[i]] = 1;
            }
            pos[na[i]] = i;
        }

        for (int i=1;i<=n;i++)
        {
            ansnum[na[i]]++;

        }
        //cout <<endl;
    }
    for (int i=1;i<=m;i++)
    {
        cout << ansnum[i] << ' ';
    }
    return 0;
}

