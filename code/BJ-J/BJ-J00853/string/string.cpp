#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        while(a--)
        {
            s+=c;
        }
    }
    int ls=s.size();
    int cnt=0;
    for(int i=0,j=ls-1;i<ls/2,j>ls/2;i++,j--)
    {
        if(s[i]!=s[j]) cnt++;
    }
    cout<<cnt;
    return 0;
}
