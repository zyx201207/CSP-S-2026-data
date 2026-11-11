#include<bits/stdc++.h>
using namespace std;
int a[300015][2];
int b[500015];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>b[i];
    }
    for(int i = n;i >= 1;i--)
    {
        for(int j = i;j <= n;j++)
        {
            a[b[j]][1]++;
            if(a[b[j]][0] != 0)
            {
                for(int f = a[b[j]][0];f < j;f++)
                {
                    a[b[f]][1]--;
                    a[b[f]][0] = 0;
                }
            }
            a[b[j]][0] = j;
        }
        for(int j = 1;j <= m;j++)
        {
            a[j][0] = 0;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout<<a[i][1]<<" ";
    }

    return 0;
}
