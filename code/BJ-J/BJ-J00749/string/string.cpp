#include<bits/stdc++.h>
using namespace std;
long long s,ans;
string n;
string re[string[n]];
int main()
{

    freopen("in.string","r",stdin);
    freopen("out.string","w",stdout);
    cin>>s;
    for(int i = 1;i <= s; i++)
    {
        int a;
        string k;
        cin>>a>>k;
        ans+=a;
        for(int j = 1;j <= a; j++)
        {
            n+=k;
        }

    }
    ans=n.size()/2;
    if(n==re[n])
    {
        cout<<"0";
        return 0;
    }
    for(int i = 1;i<=n.size()/2;i++)
        for(int j = n.size();j>=n.size()/2;j--)
        {
            if(n[i]==n[j])
            {
                ans--;
            }

        }
    cout<<ans;
    return 0;
}
