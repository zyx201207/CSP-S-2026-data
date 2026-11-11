#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    while(n--)
    {
        int op1;
        string op2;
        cin>>op1>>op2;
        while(op1--)
        {
            s+=op2;
        }
    }
    long long ans=0;
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]==s[s.size()-i-1])
        {
            continue;
        }
        else
        {
            ans++;
            s[i]=s[s.size()-i-1];
        }
    }
    cout<<ans;
    return 0;
}
