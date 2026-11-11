#include <bits/stdc++.h>

using namespace std;
string s;
int main()
{
    reopen("stringin","r",stdin);
    freopen("stringout","w",stdout);
    int n;
    cin>>n;

    int ans=0;
    int jx=0;
    for(int i=0;i<n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        ans+=a;
        for(int j=0;j<a;j++)
            s+=b;
    }
    for(int i=0;i<ans/2;i++)
    {
        int j=ans-i-1;
        if(s[i]!=s[j])
            jx++;
    }
    cout<<jx;
    return 0;
}
