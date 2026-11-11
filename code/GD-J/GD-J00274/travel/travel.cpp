#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef char ch;
typedef string str;
ll ra,rb,xa,xb;
ch rc,xc;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>ra>>rb>>rc>>xa>>xb>>xc;
    if(ra==xa)
    {
        cout<<1;
        if(rb==xb)
        {
            cout<<1;
            if(rc<='C'&&xc<='C')
            {
                cout<<1;
                if(abs(rc-xc)==1) cout<<1;
                else cout<<0;
            }
            else if(rc>='D'&&xc>='D') cout<<11;
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
}