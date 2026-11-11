#include<bits/stdc++.h>
using namespace std;
bool hw(string s)
{
    string t=s;
    reverse(s.begin(),s.end());
    return t==s;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    string j,s="";
    for(int i=1;i<=n;i++)
    {
        cin>>j;
        s+=j;
    }
    if(hw(s))
    {
        cout<<0;
        return 0;
    }

    else
    {
        for(int i=s.size()/2;i<s.size();i++)
        {
            for(int j=s.size();j>=0;j--)
            {
                if(s[i]!=s[j])
                    cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
