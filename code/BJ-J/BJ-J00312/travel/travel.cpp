#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int num = 0;
int number = 0;
int e[1000];
int main(){
    freopen("travle.in","r","stdin");
    freopen("travle.out","w","stdin");
    cin>>a>>b>>c>>d;
    for(int i = 1;i <= a;i++){
        for(int u = 1;u <=c;u++){
            if(i == u){
                e[0] = '1';

            }
            else(){
                e[0] = '0';
            }

        }


    }
    for(int y = 0,y<=c.length(),y++){
        if(y>'0'&&y<'9'){
            num += y;

        }


    }
    for(int t = 0,t<=b.length(),t++){
        if(t>'0'&&t<'9'){
            number += t;
    if(num == number){
        e[1] = '1'

    }
    else(){
        e[1] = '0'

    }
    cout<<e;
    freclose(travel.in);
    freclose(travel.out)





    return 0;
}