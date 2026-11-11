#include<bits/stdc++.h>
using namespace std;
map<long long ,long long>mp;
long long n,m,a[500005];
long long b[300005]={};
queue<int>q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        mp[a[i]]++;
        if(mp[a[i]]==2)
        {
            b[a[i]]=i;
        }
    }
    for(int i=1;i<=m;i++)
    {

        cout<<b[i]<<' ';
    }
    return 0;
}
