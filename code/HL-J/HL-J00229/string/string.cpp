#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
char c[200005];
ll a[200005];
ll s[200005];
ll x;
ll ans;

void is_Prime()
{
    int dx=x/2;
    if(x%2==0) dx++;
    for(int i=1;i<=dx;i++)
    {
        if(s[i]!=s[x-i])
        {
            ans++;
        }
    }
    cout<<ans;
}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            x++;
            s[x]=c[i]-'a';
        }
    }

    //
    //cout<<x<<endl;
    //for(int i=1;i<=x;i++)
    //{
    //    cout<<s[i]<<" ";
    //}
    //

    //for(int i=1;i<=2e5;i++) cout<<"1 a"<<endl;

    is_Prime();
    return 0;
}

