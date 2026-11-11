#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[5005],num[3005],ans[3005];
stack<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            num[j] = 0;
        }
        for(int j = i;j <= n;j++)
        {
            if(num[a[j]] != 0)
            {
                while(s.top()!=a[j])
                {
                    num[s.top()]--;
                    s.pop();
                }
                s.pop();
            }
            else num[a[j]]++;
            s.push(a[j]);
        }
        while(s.size())
        {
            ans[s.top()]++;
            s.pop();
        }


    }
    for(int i = 1;i<m;i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[m] << '\n';
    return 0;
}
