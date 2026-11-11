//GZ-J00295，卿可玥，贵阳市第一中学
#include<bits/stdc++.h>
int b[30],k[30];
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    int a[n];
    int q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        int p=1;
        int o=0;
        while(p<=a[i])
        {
            if((a[i]&p)==p)
            {
                b[o]++;
            }
            k[o]=p;
            q=max(q,o);
            p*=2;
            o++;
        }
    }
    while(1>0)
    {
        int k1=-1,k2=-1;
        for(int i=q;i>=0;i--)
        {
            if(b[i]>=m)
            {
                if(k1==-1)
                {
                    k1=i;
                }
                else if(k2==-1)
                {
                    k2=i;
                    break;
                }
            }
        }
        if(k1==-1)
        {

            cout<<ans;
            return 0;
        }
        ans+=k[k1];
        if(k2==-1)
        {
            cout<<ans;
            return 0;
        }
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            if((a[i]&k[k1])==k[k1])
            {
                int p=1;
                int o=0;
                while(p<k[k1])
                {
                    if((a[i]&p)==p)
                    {
                        b[o]++;
                    }
                    p*=2;
                    o++;
                }
            }
        }
    }
    return 0;
}
