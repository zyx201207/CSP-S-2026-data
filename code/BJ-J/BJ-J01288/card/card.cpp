#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500001],ant[300001],b[300001];
stack<long long> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int i=1;
    while (i<=n)
    {
        for (int j=1;j<=n;j++)
        {
            b[j]=0;
        }
        for (int j=i;j<=n;j++)
        {
            if (b[a[j]]==0)
            {
                b[a[j]]=1;
                s.push(a[j]);
            }
            else
            {
                while (!s.empty() && b[a[j]]==1)
                {
                    b[s.top()]=0;
                    s.pop();
                }
                b[a[j]]=1;
                s.push(a[j]);
            }
        }
        for (int j=1;j<=m;j++)
        {
            if (b[j]==1)
            {
                ant[j]++;
            }
        }
        i++;
    }
    for (int j=1;j<=m;j++)
    {
        cout << ant[j] << " ";
    }
}