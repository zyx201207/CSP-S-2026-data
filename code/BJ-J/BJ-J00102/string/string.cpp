#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,l,ans=0;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int k;
        char _;
        cin>>k>>_;
        for(int i=0; i<k; i++) s+=_;
        l+=k;
    }

    if(l%2==0)
    {
        int a,b;
        a=l/2;
        b=l/2+1;
        a--;
        b--;
        while(a>-1 && b<l)
        {
            if(s[a]==s[b]) 
            {
                a--;
                b++;
                continue;
            }
            ans++;
            a--;
            b++;
        }
    }
    else
    {
        int a,b;
        a=l/2+1;
        b=l/2+1;
        a--;
        b--;
        while(a>-1 && b<l)
        {
            if(s[a]==s[b])
            {
                a--;
                b++;
                continue;
            }
            ans++;
            a--;
            b++;
        }
    }

    cout<<ans<<"\n";
    return 0;
}