#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,ans;
string s;
bool ch(int l)
{
    for(int i=1;i<=l/2;i++)
    {
        if(s[i]!=s[l-i+1]) return false;
    }
    return true;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int l=1;
    for(int i=1;i<=n;i++)
    {
        int x;
        char y;
        cin>>x>>y;
        for(int j=1;j<=x;j++)
        {
            s[l]=y;
            l+=1;
        }
    }
    l--;
    if(ch(l))
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=l/2;i++)
    {
        if(s[i]!=s[l-i+1])
        {
            s[l-i+1]=s[i];
            ans++;
        }
        if(ch(l)==true)
        {
            //for(int j=1;j<=l;j++) cout<<s[j];
            break;
        }
    }
    //cout<<l;
    cout<<ans;
    return 0;
}