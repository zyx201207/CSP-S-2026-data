#include<bits/stdc++.h>
using namespace std;
long long s[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> a;
    for(int i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        vector<long long> b(a);
        for(int j=i+1;j<n;j++)
        {
            for(int k=i;k<j;k++)
            {
                if(b[k]==b[j]&&b[k]!=0)
                {
                    for(int o=k;o<j;o++)
                    {
                        b[o]=0;
                    }
                }
            }
        }
        for(int k=i;k<n;k++)
        {
            if(b[k]!=0)
            {
                s[b[k]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<s[i]<<" ";
    }
    return 0;
}
