#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.ans","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        int a;
        char b;
        cin>>a>>b;
        s+=string(a,b);
    }
    string t=s;
    reverse(t.begin(),t.end());
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {

        if(s[i]!=t[i])cnt++;
    }
    if(s.size()%2==1)cout<<(cnt+1)/2;
    else cout<<cnt/2;
    return 0;
}
