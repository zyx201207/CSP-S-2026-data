#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    int a[n],p[n],s[m];
    for(int i=0;i<m;i++)
        s[i]=0;
    for(int i=0;i<n;i++)
        cin>>a[n];
    for(int i=0;i<n;i++)
    {
        for(int u=0;u<n;u++)
            p[u]=a[u];
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<j;k++)
                if(p[j]==p[k])
                    for(int g=j;g<k;g++)
                        p[g]=0;
        }
        for(int z=i;z<n;z++)
            if(p[z]!=0)
                s[p[z]]++;
    }
    for(int i=0;i<m;i++)
        cout<<s[i];
}
