#include<bits/stdc++.h>
using namespace std;
string s="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=1,a;i<=n;i++)
    {
        char c;
        cin>>a>>c;
        while(a--)
            s=s+c;
    }
    for(int i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-i-1])
            ans++;
    cout<<ans<<endl;
    return 0;
}