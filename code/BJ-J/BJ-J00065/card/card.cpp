#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int c[1000005];
stack<int> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i = n;i>=1;i--)
    {
        for(int j = n-i+1;j<=n;j++)
        {
            s.push(a[j]);
            b[a[j]]++;
            if(b[a[j]] > 1)
            {
                s.pop();
                while(s.top() != a[j])
                {
                    s.pop();
                }
            }
        }
        while(!s.empty())
        {
            c[s.top()]++;
            s.pop();
        }
        for(int j = 1;j<=m;j++)
        {
            b[j] = 0;
        }
    }
    for(int i = 1;i<=m;i++)
    {
        if(c[i] != 0)
        {
            cout << c[i] << ' ';
        }
    }
    return 0;
}
