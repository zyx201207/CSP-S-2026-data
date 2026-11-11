#include <bits/stdc++.h>
using namespace std;
struct seat{
    int id,r;
    char c;
    void read(){
        cin>>id;
        char ch;
        cin>>ch;
        r=ch-'0';
        cin>>ch;
        r=r*10+ch-'0';
        cin>>ch;
        c=ch;
    }
};
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    seat a,b;
    a.read();
    b.read();
    int a1=0,a2=0,a3=0,a4=0;
    if(a.id==b.id){
        a1=1;
        if(a.r==b.r){
            a2=1;
            if(('A'<=a.c&&a.c<='C'&&'A'<=b.c&&b.c<='C')||('D'<=a.c&&a.c<='E'&&'D'<=b.c&&b.c<='E')){
                a3=1;
                if(abs(a.c-b.c)==1&&!(a.c=='C'&&b.c=='D')&&!(a.c=='D'&&b.c=='C')){
                    a4=1;
                }
            }
        }
    }
    cout<<a1<<a2<<a3<<a4;
    return 0;
}
