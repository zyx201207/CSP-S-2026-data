#include <bits/stdc++.h>
using namespace std;
struct ticket{
    string c;
    string s;
};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ticket a,b;
    int m=4;
    cin>>a.c>>a.s;
    cin>>b.c>>b.s;
    if(a.c==b.c){
        cout<<1;
        m--;
        if((a.s[0]+a.s[1])==(b.s[0]+b.s[1])){
            cout<<1;
            m--;
            if(a.s[2]<='C'&&b.s[2]<='C' || ((a.s[2]=='F'||a.s[2]=='D')&&(b.s[2]=='F'||b.s[2]=='D'))){
                cout<<1;
                m--;
                if(((a.s[2]-1==b.s[2]) || (a.s[2]+1==b.s[2]))&&!((a.s[2]=='D'&&b.s[2]=='C')||(a.s[2]=='C'&&b.s[2]=='D'))){
                    cout<<1;
                    m--;
                }
            }
        }

    }
    for(int i=0;i<m;i++){
        cout<<0;
    }
    return 0;
}



