#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,a[514514],b[514514];
vector<int> v;
bool f[5145];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(!f[a[i]])
            {
                v.push_back(a[i]);
                f[a[i]]=1;
            }
            else
            {
                for(int k=0;k<v.size();k++)
                {
                    if(v[k]==a[i])
                    {
                        for(int l=v[k];l>=0;l--)
                        {
                            v[l]=-1;
                            f[v[l]]=0;
                        }
                    }
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<v.size();k++)
            {
                if(v[k]==j) b[j]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
