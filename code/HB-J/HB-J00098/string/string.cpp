#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define int128 __int128_t
#define pq priority_queue
using namespace std;
const string CSPPUO="string";
int main()
{
    #ifndef cspjudge
    string filename_in=CSPPUO+".in";
    string filename_out=CSPPUO+".out";
    freopen(filename_in.c_str(),"r",stdin);
    freopen(filename_out.c_str(),"w",stdout);
    #endif
    int n;
    cin>>n;
    string a;
    int c;
    char d;
    a="";
    for(int i=0;i<n;i++)
    {
        cin>>c>>d;
        while(c--)
        {
            a+=d;
        }
    }
    ll ans=0;
    for(ll i=0;i<a.length()/2;i++)
    {
        if(a[i]!=a[a.length()-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

