#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    int a,c,e,f;
    string b,d;
    cin>>a>>e>>b>>c>>f>>d;
    if(a==c){
        cout<<'1';
    }else{
        cout<<'0';
    }
    if(e==f){
        cout<<'1';
    }else{
        cout<<'0';
    }
    if(b=="A"||b=="B"||b=="C"){
        if(d=="A"||d=="B"||d=="C"){
            cout<<'1';
        }
        if((b=="A"&&d=="B")||(b=="B"&&d=="A"||d=="C")||(b=="C"&&d=="B")){
            cout<<'1';
        }
    }else if(b=="D"||b=="f"){
        if(d=="D"||d=="F"){
           cout<<'1';
        }
    }else{
        cout<<'0';
    }
    return 0;
}
