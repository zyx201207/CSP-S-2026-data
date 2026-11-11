#include<bits/stdc++.h>
using namespace std;
int n,m;
struct travel{
    int t;
    char r;
};
travel g,h;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>n;
    cin>>g.t>>g.r;
    cin>>m;
    cin>>h.t>>h.r;




    if(n==m&&g.t==h.t){
        if(g.r=='A'&&h.r=='B'||g.r=='B'&&g.r=='A'||g.r=='B'&&g.r=='C'||g.r=='C'&&g.r=='B'||g.r=='D'&&g.r=='F'||g.r=='F'&&g.r=='D'){
            cout<<1111;
            return 0;
        }
    }
    if(n==m&&g.t==h.t&&g.r<='C'&&g.r>='A'&&h.r<='C'&&h.r>='A'||n==m&&g.t==h.t&&g.r=='D'&&h.r=='F'||n==m&&g.t==h.t&&g.r=='F'&&h.r=='D'){
        cout<<1110;
        return 0;
    }
    if(n==m&&g.t==h.t){
        cout<<1100;
        return 0;
    }
    if(n==m){
        cout<<1000;
        return 0;
    }

    return 0;
}


