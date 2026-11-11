#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
       int x;
       char y;
       cin>>x>>y;
       for(int j = 1;j<=x;j++)
       {
           s+=y;
       }
    }
    for(int i = 0;i<n/2+1;i++)
    {
        if(s[i]!=s[s.length()-1-i])
        {
            ans++;
        }
    }
    //cout<<s<<endl;
    cout<<ans;
    return 0;
}
