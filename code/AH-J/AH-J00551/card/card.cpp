#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,js,b[500005],qq=0;
string a[500005];
string z;
bool f=0;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1])
        {
            f=1;
        }
        if(a[i]==a[i-1])
        {
            qq++;
        }
    }
    if(f==0)
    {
        for(i=1;i<=m;i++)
        {
            cout<<n-qq<<' ';
        }
        return 0;
    }
    for(js=1;js<=n;js++)
    {
        z.clear();
        for(i=js,j=0;i<=n;i++,j++)
        {
            if(z.find(a[i])==EOF)
            {
                z.insert(z.size(),a[i]);
            }
            else
            {
                long long x=z.find(a[i]);
                j=x;
                z.erase(x,z.size());
                z.insert(z.size(),a[i]);
            }
        }
        for(i=1;i<=m;i++)
        {
            if(z.find(char(i+48))!=EOF)
                b[i]++;
        }
    }
    for(i=1;i<=m;i++)
    {
        cout<<b[i]<<' ';
    }
    return 0;
}

