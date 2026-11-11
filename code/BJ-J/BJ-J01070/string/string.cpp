#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    char b;
    string s;
    int b2;
    bool ok=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(int i=1;i<=a;i++)
        {
            s.push_back(b);
        }
        if(b2!=b)
            ok=0;
        b2=b;
    }
    int sum=0;
    if(ok)
        cout<<0;
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1-i])
        {
            sum++;
        }
    }
    cout<<sum;
}
