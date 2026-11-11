#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
bool flag[500005];
int head,rear;
int cnt;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int t = 0;t < m;t++)
    {
        for(int i = 0;i < n;i++)
        {
            cin >> a[i];
            if(!flag[a[i]])
            {
                b[rear] = a[i];
                flag[a[i]] = true;
                rear++;
            }
            else
            {
                for(int j = 0;j <= rear;j++)
                {
                    b[j] = 0;
                }
                rear = 0;
            }

        }
        for(int i = 0;i < rear;i++)
        {
            if(b[i] == a[i])
                cnt++;
        }
        cout << cnt << " ";
        cnt = 0;
    }

    return 0;
}