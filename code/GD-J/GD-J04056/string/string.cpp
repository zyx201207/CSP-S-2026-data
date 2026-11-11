#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    long long n,ans1=0,ans2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string c="";
        long long a;
        cin>>a;
        cin>>c;
        for(int i=0;i<a;i++)
        {
            s+=c;
        }
    }
    for(int i=s.length()-1;i>s.length()/2+1;i--)
    {
        if(s[i]!=s[(s.length()/2+1)*2-i])
        {
            s[i]=s[(s.length()/2+1)*2-i];
            ans1++;
        }
    }
    for(int i=0;i<s.length()/2+1;i++)
    {
        if(s[i]!=s[(s.length()/2+1)*2-i])
        {
            s[i]=s[(s.length()/2+1)*2-i];
            ans2++;
        }
    }
    cout<<max(ans1,ans2);
    return 0;
}
