#include<iostream>
using namespace std;
int n,m,s[500010],v[500010],ms[300010],u;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
    {
        u=0;
        for(int k=0;k<n-i+1;k++)
        v[k]=0;
        for(int j=i;j<n;j++)
        {
            v[u]=s[j];
            u++;
            for(int k=0;k<u;k++)
            if(v[k]==v[u])
            {
            for(int l=k+1;l<=u;l++)
            v[l]=0;
            u=k;
            }
        }
        for(int j=0;j<=u;j++)
        ms[v[j]]++;
    }
    for(int i=0;i<m;i++)
        cout<<ms[i]<<" ";
    return 0;
}
