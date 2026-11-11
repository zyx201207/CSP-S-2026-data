#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define int128 __int128_t
#define pq priority_queue
using namespace std;
const string CSPPUO="travel";
int main()
{
    #ifndef cspjudge
    string filename_in=CSPPUO+".in";
    string filename_out=CSPPUO+".out";
    freopen(filename_in.c_str(),"r",stdin);
    freopen(filename_out.c_str(),"w",stdout);
    #endif
    int a,b,d,e;
    char c,f;
    cin>>a>>b>>c>>d>>e>>f;
    if(a==d)
    {
        if(b==e)
        {
            if((c<='C'&&f<='C')||(c>'C'&&f>'C'))
            {
                if((int)f-(int)c==-1||(int)f-(int)c==1)
                {
                    cout<<"1111";
                }
                else
                {
                    cout<<"1110";
                }
            }
            else
            {
                cout<<"1100";
            }
        }
        else
        {
            cout<<"1000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
//freopen
//freopen

