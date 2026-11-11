#include <bits/stdc++.h>
using namespace std;
long long ans;
long long u;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>u;
        char o;
        cin>>o;
        for(int i=1;i<=u;i++)
        {
            s+=o;
        }
    }
    long long l=s.size();
    for(int i=0;i<l/2;i++)
    {
        if(s[i]!=s[l-1-i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}