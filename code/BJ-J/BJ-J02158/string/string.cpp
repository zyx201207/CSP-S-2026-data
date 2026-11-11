#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010];
char c[200010];
ll n,all,b[200010];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin>>n;
    b[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++) s+=c[i];
        all+=a[i];
    }
    ll half=(all+1)/2;
//   cout<<s;

    ll ans=0;
//    cout<<all<<" "<<half<<endl;
    if(all%2==0)
    {
        for(int i=half+1;i<=all;i++)
        {
            if(s[i-1]!=s[all-i]) ans++;
        }
    }
    else
    {
        for(int i=half+1;i<=all;i++)
        {
            if(s[i-1]!=s[all-i]) ans++;
        }
    }
    cout<<ans;
    return 0;
}
