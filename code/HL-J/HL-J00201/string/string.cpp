#include <bits/stdc++.h>
using namespace std;
string c,d;
int w[10001];
bool v=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,k;
    cin>>n;
    string t;
    if(n==1)
    {
        cin>>k>>t;
        cout<<0;
        return 0;
    }
    else if(n==2)
    {
        int a,b;
        string p,q;
        cin>>a>>p>>b>>q;
        if(p==q)
        {
            cout<<0;
        }
        else
        {
            if(a>b)
            {
                cout<<b;
            }
            else if(a<b)
            {
                cout<<a;
            }
            if(a==b)
            {
                cout<<a;
            }
        }
        return 0;
    }
    char s[10001];
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(w[i]!=1)
        {
            v=1;
            break;
        }
    }
    long long ans=0;
    if(v==0)
    {
        for(int i=1;i<=n/2;i++)
        {
            if(s[i]!=s[n-i+1])
            {
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }

    for(int i=1;i<=n/2;i++)
    {
        if(s[i]!=s[n-i+1]&&s[i]!=s[i+1])
        {
            ans+=min(w[i],w[n-i+1]);
            w[i+1]+=(max(w[i],w[n-i+1])-min(w[i],w[n-i+1]));
        }
        else if(s[i]!=s[n-i+1]&&s[i]==s[i+1])
        {
            ans+=min(w[i],w[n-i+1]);
            w[i+1]+=(w[i]-min(w[i],w[n-i+1]));
        }
        else if(s[i]==s[n-i+1]&&s[i]!=s[i+1])
        {
            ans+=(max(w[i],w[n-i+1])-min(w[i],w[n-i+1]));
            w[i+1]+=(max(w[i],w[n-i+1])-min(w[i],w[n-i+1]));
        }
        else
        {
            w[i+1]+=(max(w[i],w[n-i+1])-min(w[i],w[n-i+1]));
        }
    }
    cout<<ans;
    return 0;
}
