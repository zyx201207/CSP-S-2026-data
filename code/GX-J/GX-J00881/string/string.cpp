#include<bits/stdc++.h>
using namespace std;

string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,x=0;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int i=0;i<a;i++)
        {
            s+=c;
        }
    }
    for(int i=0;i<=s.size()/2;i++)
    {
        if(s[i]!=s[n-i])
        {
            x++;
            s[n-i]=s[i];
        }
    }
    cout<<x;
    return 0;
}
