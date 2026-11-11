#include<bits/stdc++.h>
using namespace std;
int cx,cx2;
string id,id2;
int f(char c){
    if(c=='D'||c=='F')return 0;
    return 1;
}
bool f2(char x,char y){
    if(x=='A'&&y=='C'||x=='C'&&y=='A')return 0;
    return 1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cx>>id>>cx2>>id2;
    if(cx!=cx2){
        cout<<"0000";
    }else{
        if(id.substr(0,2)!=id2.substr(0,2)){
            cout<<"1000";
        }else{
            if(f(id[2])!=f(id2[2])){
                cout<<"1100";
            }else{
                if(f(id[2])==0||f2(id[2],id2[2])){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
            }
        }
    }
    return 0;
}
