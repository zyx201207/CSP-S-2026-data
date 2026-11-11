#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
char c[N];
ll a[N];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,sum=0,f=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>c[i];
        if(a[i]!=1)f=1;
    }
    ll ans=0;
    string s;
    for(int i=1; i<=n; i++)
        for(int j =1; j<=a[i]; j++)
            s+=c[i];
    for(int i=0,j=s.size()-1; i<j; i++,j--)
    {
        if(s[i]!=s[j])ans++;
    }
    cout<<ans;
    return 0;
    //Trick||Treat!
}
