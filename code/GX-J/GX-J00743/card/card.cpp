#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],box[5000005],box1[500005],b[500005];
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; i++)
        {
            b[j] = a[i];
            box1[j]++;
            for (int k = 1; k <= m; k++)
            {
                if (box1[k] > 1)
                {
                    //ababab,I can,t do wuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuwuT^T
                }
            }
        }
    }
    return 0;
}
