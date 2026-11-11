#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],Map[1000001],Find[1000001],has[1000001],f[1000001];
bool flag=true;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    a[0]=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]=max(f[a[i]],i);
        if(a[i]<a[i-1])
        {
            flag=false;
        }
    }
    if(flag==true)
    {
        for(int i=1;i<=m;i++)
        {
            cout<<f[i]<<" ";
        }
        return 0;
    }
    for(int k=1;k<=n;k++)
    {
        vector<int> card;
        card.push_back(0);
        for(int i=k;i<=n;i++)
        {
            Find[a[i]]++;
            card.push_back(a[i]);
            if(Find[a[i]]>=2)
            {
                for(int i=Map[a[i]];i<card.size()-1;i++)
                {
                    if(card[i]!=0)
                    {
                        Find[card[i]]--;
                        card[i]=0;
                    }
                }
            }
            Map[a[i]]=card.size()-1;
        }
        for(int i=1;i<=m;i++)
        {
            if(Find[i]>0)
            {
                has[i]++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            Find[i]=0;
            Map[i]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<has[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}