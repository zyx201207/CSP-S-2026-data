#include <bits/stdc++.h>
using namespace std;

int a[300001];
int b[500001];
int c[300001];

int main()
{
    freopen("card.in","r",std);
    freopen("card.out","w",std);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<n;i++)
    {
        cin >> b[i];
    }

    for(int i = 0;i<n;i++)
    {
        int cur = 1;
        for(int j = i;j<n;j++)
        {
            if(c[b[j]]==0)
            {
                c[b[j]] = cur;
                cur++;
            }
            else
            {
                for(int y = 0;y<=m;y++)
                {
                    if(c[y]>c[b[j]])
                    {
                        c[y] = 0;
                        cur = c[b[j]]+1;
                    }
                }
            }
        }
        for(int j = 0;j<=m;j++)
        {
            if(c[j]>0)
            {
                c[j] = 0;
                a[j]++;
            }
        }
    }
    for(int i = 1;i<=m;i++)
    {
        cout << a[i] << " ";
    }
}