#include<bits/stdc++.h>
using namespace std;

int n,m,a[300005],cnt[500005];
vector<int>x;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int y=a[j];
            for(int k=0;k<x.size();k++)
            {
                if(y==x[k])
                {
                    x.erase(x.begin()+k,x.begin()+x.size()-k);
                    break;
                }
            }
            x.push_back(y);
        }
        for(int j=0;j<x.size();j++)
        {
            cnt[x[j]]++;
        }
        x.clear();
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
