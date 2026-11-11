#include <bits/stdc++.h>
using namespace std;
long long n,f[10000005],ans,m,a[10000005],s[1000005],lat[1000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    //memset(f,0x3f,sizeof(f));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
     for(int i=n;i>=1;i--)
    {
        for(int i=1;i<=m;i++)cout<<f[i]<<" ";
        cout<<"\n";
        if(s[a[i]]==0)
        {
            f[a[i]]+=i;
            s[a[i]]=1;
        }
        else
        {
            //cout<<lat[a[i]]<<"\n";
            for(int j=i;j<lat[a[i]];j++)
            {
                if(s[a[j]])f[a[j]]-=i;
                s[a[j]]=0;
            }

        }
        lat[a[i]]=i;
    }
    for(int i=1;i<=m;i++)cout<<f[i]<<" ";
    return 0;
}
