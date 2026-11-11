#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int d[1000000];
vector<int> b;
int main()
{
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n=0,m=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++)
    {

        for(int j=i;j<=n;j++)
        {
            for(int k=0;k<b.size();k++)
            {
                if(b[k]==a[j])
                {
                    for(int o=k;o<b.size();o++)
                    {

                        b[o]=0;
                    }

                }

            }
            b.push_back(a[j]);

        }
        for(int j=0;j<b.size();j++)
        {
            d[b[j]]++;

        }
        b.clear();
    }
    for(int i=1;i<=m;i++)
    {
        cout<<d[i]<<" ";
    }
    return 0;
}

