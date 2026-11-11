#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        string c;cin>>c;
        s+=c;
    }

    int l=s.size(),ans=0;
    for(int i=l/2+1;i<=l;i++)
    {
        if(s[i]!=s[l-i+1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
