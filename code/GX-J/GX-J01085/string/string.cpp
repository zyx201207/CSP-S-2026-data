#include<bits/stdc++.h>
using namespace std;
long long n,x,ans=0;
string a;
char y;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        for(int j=1;j<=x;j++)
        {
            a.push_back(y);
        }
    }
    for(int i=0;i<a.size()/2;i++)
    {
        if(a[i]!=a[a.size()-1-i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
