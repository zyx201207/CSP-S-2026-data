#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500003]={};
    cin >> n >> m;
    map<int,int>w,l;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        stack<int> s;
        for(int j = i;j <= n;j++)
        {
            w[a[j]] ++;
            if(w[a[j]] == 1) s.push(a[j]);
            else
            {
                while(s.top() != w[a[j]])
                {
                    w[s.top()] --;
                    s.pop();
                }
            }

        }
        for(int k = 1;k <= s.size();k++)
        {
            l[s.top()] ++;
            s.pop();
        }
        for(int r = 1;r <= m;r++)
        {
            w[r] = 0;
        }
    }
    for(int i = 1;i <= m; i++)
    {
        cout << l[i] << " ";
    }
    return 0;
}
