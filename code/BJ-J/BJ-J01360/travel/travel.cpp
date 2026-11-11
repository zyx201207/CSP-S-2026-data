#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII piar<int,int>
#define x first
#define y second
#define ls p<<1
#define rs p<<1|1
#define pb push_back

const int N=5e5+10,Z=1e18,M=3e5+10;

int n,t;
string a,b,c,d;

void qweasd(){
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b.substr(0,2)==d.substr(0,2)){
            cout<<1;
            if((b[2]-'A'<=2&&d[2]-'A'<=2)||(b[2]-'A'>3&&d[2]-'A'>2)){
                cout<<1;
                if(abs(b[2]-d[2])==1) cout<<1;
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    cout<<endl;

    //diff travel5.ans travel5.out
}

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    t=1;

    while(t--){

        qweasd();

    }
    return 0;
}
