#include<iostream>
#include<string>
using namespace std;
int n,ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string s;
    while(n--)
    {
        int a;
        char t;
        cin>>a>>t;
        while(a--)s+=t;
    }
    int len=s.size();
    for(int i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-i-1])ans++;
    }
    cout<<ans;
    return 0;
}