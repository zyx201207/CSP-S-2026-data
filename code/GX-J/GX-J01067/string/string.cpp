#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,cnt=0;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string d;
        cin>>m>>d;
        for(int j=0;j<m;j++)
        {
            s+=d;
        }
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            s[s.size()-i]=s[i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
