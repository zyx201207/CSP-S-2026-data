#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    vector<int> ori;
    vector<int> ans[500001];
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ori.push_back(x);
    }
    for(int times=1;times<=n;times++)
    {
        vector<int> a=ori;
        vector<int> zm;
        for(int i=1;i<=n;i++)
        {
            for(auto j:zm)
            {
                if(j==a[i])
                {
                    while(zm[zm.size()-1]!=j) zm.pop_back();
                    zm.pop_back();
                }
            }
            zm.push_back(a[i]);
        }
        ans[times]=zm;
    }
    for(int i=1;i<=m;i++)
    {
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            for(auto k:ans[j])
            {
                if(k==i)
                {
                    sum++;
                    break;
                }
            }
        }
        printf("%d ",sum);
    }
    return 0;
}
