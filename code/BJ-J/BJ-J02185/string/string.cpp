#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++) s+=c;
    }
    //cout<<s<<endl;
    long long l=s.size(),cnt=0;
    if(l%2==0)
    {
        for(int i=0;i<l/2;i++)
        {
            if(s[i]!=s[l-i-1]&&'a'<=s[i]<='z'&&'a'<=s[l-i-1]<='z') cnt++;
        }
    }
    else
    {
        for(int i=0;i<l/2;i++)
        {
            if(s[i]!=s[l-i-1]&&'a'<=s[i]<='z'&&'a'<=s[l-i-1]<='z') cnt++;
            //cout<<i<<" "<<s[i]<<" "<<s[l-i-1]<<endl;
        }
    }
    cout<<cnt;
    return 0;
}