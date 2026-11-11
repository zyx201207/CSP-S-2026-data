#include<bits/stdc++.h>
using namespace std;
int a[200005];
string b[100005],s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>b[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=b[i];
        }
    }
    string s1=s;
    reverse(s1.begin(),s1.end());
    if(s1==s)
    {
        cout<<0;
    }
    else
    {
        s=' '+s;
        int f=s.size()/2;
        long long ans=0;
        for(int i=s.size();i>f;i--)
        {
            ans+=(s[i]==s[s.size()-i+1]?0ll:1ll);
        }
        cout<<ans;
    }
    return 0;
}