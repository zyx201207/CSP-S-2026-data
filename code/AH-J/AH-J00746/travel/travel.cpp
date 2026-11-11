#include<iostream>
#include<cstdio>
using namespace std;
string a,b,c,d;
bool check1(){
    if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
        return d[2]=='A'||d[2]=='B'||d[2]=='C';
    }return d[2]=='D'||d[2]=='F';
}bool check2(){
    if(b[2]<='C')return b[2]-d[2]==1||b[2]-d[2]==-1;
    return 1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            if(check1()){
                cout<<1;
                if(check2()){
                    cout<<1;
                }else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }
    else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
