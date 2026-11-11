#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
long long L,ans;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>a>>c;
        L+=a;
        while(a--) s+=c;
    }
    s=" "+s;
    for(int i=1;i<=L/2;i++)
        if(s[i]!=s[L+1-i])
            ans++;
    cout<<ans;
    return 0;
}