#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,sum=0,len;
int d[200005];
bool m[200005];
vector<int> hsz[35];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    len=a;
    for(int i=1;i<=a;i++)
    {
        cin>>d[i];
    }
    for(int i=31;i>=1;i--)
    {
        for(int j=1;j<=a;j++)
        {
            if(m[j]) continue;
            if(d[j]<(1<<(i-1)) || ((d[j]>>(i-1)) & 1)!=1)
            {
                m[j]=1;
                len--;
                hsz[i].push_back(j);
            }
        }
        if(len>=b)
        {
            sum+=(1<<(i-1));
        }
        else
        {
            for(int j=0;j<hsz[i].size();j++)
            {
                m[hsz[i][j]]=0;
                len++;
            }
        }
    }
    cout<<sum;
    return 0;
}
