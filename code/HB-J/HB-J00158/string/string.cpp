#include<bits/stdc++.h>
using namespace std;
long long n,l,ans=0;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    l=0;
    bool t=1;
    for(int i=1;i<=n;i++)
    {
        int x;
        char c;
        cin>>x>>c;
        while(x>0)
        {
            s[l]=c;
            l++;
            x--;
        }
    }
    l--;
    for(int i=0;i<=l/2;i++)
    {
        if(s[i]!=s[l-i])
        {
            ans++;
        }
    }
    cout<<ans;
}
