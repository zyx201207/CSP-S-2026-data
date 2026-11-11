#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a1, a2, b1, b2;
char x, y;

bool check(char a, char b){
    if(a>b) swap(a, b);
    if(a=='A'&&b=='B') return 1;
    if(a=='B'&&b=='C') return 1;
    if(a=='D'&&b=='F') return 1;
    return 0;
}

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin>>a1>>a2>>x>>b1>>b2>>y;
    if(a1==b1){
        cout<<1;
        if(a2==b2){
            cout<<1;
            if((x<='C'&&y<='C')||(x>='D'&&y>='D')){
                cout<<1;
                if(check(x, y)==1)
                    cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}