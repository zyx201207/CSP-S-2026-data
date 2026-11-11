#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int id(string a){
    return ((int)a[0])*10 + ((int)a[1]);
}
int seat(string a){
    return (int)a[2];
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n,m,ant1,ant2;
    cin>>n>>ant1>>m>>ant2;
    if(n == m) cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(id(ant1) == id(ant2)){
        cout<<1;
        if((seat(ant1)<=67 && seat(ant2)<=67) || (seat(ant1)>=68 && seat(ant2)>=68)){
            cout<<1;

            if(seat(ant1) <= 67 ){
                if(seat(ant1) == (seat(ant2)+1) || seat(ant1) == (seat(ant2)-1)) cout<<1;
                else cout<<0;
            }else if(seat(ant1)>=67){
                if(seat(ant1) == (seat(ant2)+2) || seat(ant1) == (seat(ant2)-2)) cout<<1;
                else cout<<0;
            }else cout<<0;

        }else cout<<0<<0;
    }else cout<<0<<0<<0;

    return 0;
}
