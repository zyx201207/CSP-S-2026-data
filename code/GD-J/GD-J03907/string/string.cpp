#include <bits/stdc++.h>
using namespace std;
string s,a;
int n,x,cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>a;
        for(int i=1;i<=x;i++)
        {
            s+=a;
        }
    }
    int m=s.size();
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=s[m-i])
        {
            cnt++;
        }
    }
    cout<<cnt-1;
    return 0;
}
