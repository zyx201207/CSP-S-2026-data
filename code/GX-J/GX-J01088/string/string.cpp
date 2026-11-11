#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    string S,s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s;
        for(int j=0;j<a[i];j++)
        {
            S+=s;
        }

    }
    int x=S.size();
    for(int i=0;i<x/2;i++)
    {
        if(S[x-i-1]!=S[i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
