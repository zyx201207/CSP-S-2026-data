#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s;
string fz(string a)
{
    string b;
    for(int i=a.size()-1;i>=0;i--)b+=a[i];
    return b;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--)
    {
        int a;
        string c;
        cin>>a>>c;
        for(long long i=1;i<=a;i++)s+=c;
    }
    if(s.size()%2==0)
    {
        string sb;
        for(long long i=0;i<s.size()/2;i++)sb+=s[i];
        sb+=fz(sb);
        for(long long i=s.size()/2+1;i<s.size();i++)
        {
            if(sb[i]!=s[i])ans++;
        }
    }
    else{
        string sb;
        for(long long i=0;i<s.size()/2;i++)sb+=s[i];
        sb+=s[s.size()/2]+fz(sb);
        for(long long i=s.size()/2+1;i<s.size();i++)
        {
            if(sb[i]!=s[i])ans++;
        }
    }
    cout<<ans;
    return 0;
}
