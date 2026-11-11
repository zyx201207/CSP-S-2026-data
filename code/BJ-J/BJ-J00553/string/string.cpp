#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t;
    cin>>t;
    string s;
    while(t--)
    {
        int x;
        char c;
        cin>>x>>c;
        while(x--)s+=c;
    }
    string s1;
    s1=s;
    reverse(s.begin(),s.end());
    int cnt=0;
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s1[i])cnt++;
    }
    cout<<cnt;
    return 0;
}
