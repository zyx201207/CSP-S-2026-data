#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define dd double
#define ull unsigned long long
#define pq priority_queue
#define vec vector
using namespace std;
const int MAXN=2e6+5;
const int NN=5005;
ll c,T,togo[MAXN],dis[NN][NN];
int n,d;
const string PUO="migrate";
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef cspjudge
    string filename_in=PUO+".in";
    string filename_out=PUO+".out";
    freopen(filename_in.c_str(),"r",stdin);
    freopen(filename_out.c_str(),"w",stdout);
    #endif
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=0;i<n;i++)
        {
            cin>>togo[i];
        }

    }
    return 0;
}

