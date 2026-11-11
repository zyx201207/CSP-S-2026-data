#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using pi=pair<int,int>;
#define fi first
#define se second
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<1;
        string p1=b.substr(0,2);
        string p2=d.substr(0,2);
        // cout<<p1<<' '<<p2<<'\n';
        if(p1==p2)
        {
            cout<<1;
            char c1=b[2];
            char c2=d[2];
            if((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C'))
            {
                cout<<1;
                if(abs((int)c1-(int)c2)<=1)
                {
                    cout<<1<<'\n';
                }
                else
                {
                    cout<<0<<'\n';
                }
            }
            else
            {
                cout<<"00"<<'\n';
            }
        }
        else
        {
            cout<<"000"<<'\n';
        }
    }
    else
    {
        cout<<"0000"<<'\n';
    }
    return 0;
}