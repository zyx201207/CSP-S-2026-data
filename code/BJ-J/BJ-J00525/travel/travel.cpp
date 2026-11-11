#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.ans","w",stdout);

    int a,s,b,h;
    char c,d;
    cin>>a;
    cin>>b>>c;
    cin>>s;
    cin>>h>>d;
    if(a == s){
      cout<<1;
    }else{
        cout<<0;
    }if(b == h){
    cout<<1;
    }else{
        cout<<0;
    }if(c == 'A'||c=='B'||c=='C'){
        if(d == 'A'||d == 'B'||d == 'C'){
            cout<<1;
        }
    }else{
        cout<<0;
    }if(c == 'D'||c=='F'){
        if(d == 'D'||d == 'F'){
            cout<<1;
        }
    }
        if(c == 'A'&&d == 'B'){
                cout<<1;
    }if(c == 'B'&&d == 'A'){
        cout<<1;
    }if(c == 'B'&&d == 'C'){
    cout<<1;
    }if(c == 'C'&&d== 'B'){
        cout<<1;
    }if(c == 'F'&&d== 'D'){
        cout<<1;
    }if(c == 'D'&&d== 'F'){
        cout<<1;
    }else{
        cout<<0;
    }

    return 0;
    }
