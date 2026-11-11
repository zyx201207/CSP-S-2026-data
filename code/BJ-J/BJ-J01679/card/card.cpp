#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[500005];
queue<int> q;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        while(!q.empty()) q.pop();
        for(int j = i+1;j <= n;j++)
        {
            q.push(a[j-1]);
            q.push(a[j]);
            bool check = 1;
            int x = q.size();
            for(int k = 1;k <= x;k++)
            {
                if(check == 0) q.pop();
                else
                {
                    if(q.front() == a[j])
                    {
                        check = 0;
                        q.pop();
                    }
                    else
                    {
                        q.push(q.front());
                        q.pop();
                    }
                }
            }
        }
        while(!q.empty())
        {
            cout << q.front() << " ";
            b[q.front()]++;
            q.pop();
        }
        cout << endl;
    }
    for(int i = 1;i <= m;i++) cout << b[i] << " ";
    return 0;
}
