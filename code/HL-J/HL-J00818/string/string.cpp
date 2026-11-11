#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
string a,y;
int main()
{
    freopen(string.in,"r",stdin);
    freopen(string.out,"w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        for(int i=1;i<=x;i++)
        {
            a+=y;
        }
    }
    for(int i=0;i<(a.size())/2;i++)
    {
        if(a[i]!=a[(a.size())-i-1])ans++;

    }
    cout<<ans;
    return 0;

}
