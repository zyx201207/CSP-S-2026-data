#include <bits/stdc++.h>
using namespace std;
int b[3005];
int a[3005];
int c[3005];
int q[3005];
int cnt = 1;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n>>m;
    for(int i= 1;i<=n;i++)
    {

        cin >>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j <=n;j++)
        {
            if(b[a[j]] != 0)
            {
                b[a[j]] = 0;
                while(q[cnt] != a[j])
                {
                    q[g] =0;
                    cnt--;
                }
            }
            b[a[j]]++;
            q[cnt]=a[j];
            cnt++;
        }
        for(int o=1;o <=3005;o++)
        {
            c[q[o]]++;
        }
        cnt=1;
    }
    for(int i=1;i<=m;i++)
    {
            cout <<c[i]<<" ";
    }
    return 0;
}
