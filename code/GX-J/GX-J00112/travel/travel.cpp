#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    int n=0;
    if(a==c){
        n+=1000;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if((b[0]==d[0])&&(b[1]==d[1])){
        n+=100;
    }
    else{
        cout<<n;
        return 0;
    }
    if((b[2]>=68&&b[2]<=70)&&(b[2]>=68&&b[2]<=70)||(b[2]>=64&&b[2]<=66)&&(b[2]>=64&&b[2]<=66)){
        n+=10;
    }
    else{
        cout<<n;
        return 0;
    }
    if((b[2]+2)==(d[2]+1)||(b[2]-2)==(d[2]-1)){
        n+=1;
    }
    else{
        cout<<n;
        return 0;
    }
    cout<<n;
    return 0;
}
