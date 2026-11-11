#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e6;
long long s[maxn],a[maxn];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long ans=-1;
    for(int i=1;i<=n;i++)
    {
        for(int i=1;i<=n;i++)
        {
            s[i]=a[i];
        }
        long long ax=-1,ay=s[i];
        s[i]=-1;
        for(int j=1;j<m;j++)
        {
            ax=-1;
            int k,g;
            for(k=i;k<=n;k++)
            {
                if(s[k]!=-1&&(ay&s[k])>ax)
                {
                    ax=s[k]&ay;
                    g=k;
                }
            }
            s[g]=-1;
            ay=ax;


        }
        ans=max(ans,ax);
    }
    cout<<ans;
}
