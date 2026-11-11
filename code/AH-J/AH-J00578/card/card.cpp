#include<bits/stdc++.h>
using namespace std;
int a[500005],t[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int l=1,tc=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<"---"<<endl;
        map<int,int>tc;
        for(int j=l;j<=n;j++)
        {
            tc[a[j]]++;
            if(tc[a[j]]>=2)
            {
                for(int k=1;k<=j;k++)tc[a[k]]=0;
                tc[a[j]]++;
            }
        }
        for(int j=1;j<=m;j++)
        {
            //cout<<tc[j]<<endl;
            if(tc[j]>=1)t[j]++;
            tc[j]=0;
        }
        l++;
    }
    for(int i=1;i<=m;i++)cout<<t[i]<<" ";
    return 0;
}
