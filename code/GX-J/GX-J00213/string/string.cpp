#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=1; i<=n; i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int j=1; j<=a; j++)
        {
            s+=c;
        }
    }
    if(s.size()%2!=0)s[s.size()/2]=' ';
    long long cnt=0;
    if(s.size()%2!=0)
    {
        for(int i=0; i<s.size()/2; i++)
        {
            if(s[i]!=s[i+s.size()/2+1])
            {
                cnt++;
            }
        }
    }
    else
    {
        for(int i=0; i<s.size()/2; i++)
        {
            if(s[i]!=s[i+s.size()/2])
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
