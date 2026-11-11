#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        if(b[1]==d[1] && b[2]==d[2]){
            cout<<"1";
            if(b[3]=='A' || b[3]=='B' || b[3]=='C'){
                if(d[3]=='A' || d[3]=='B' || d[3]=='C'){
                    cout<<"1";
                    if(b[3]+1==d[3] || b[3]-1==d[3]){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
                }else{
                    cout<<"00";
                }
            }else if(b[3]=='D' || b[3]=='F'){
                if(d[3]=='D' || d[3]=='F'){
                    cout<<"1";
                    if(b[3]+1==d[3] || b[3]-1==d[3]){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
                }else{
                    cout<<"00";
                }
            }
        }else {
            cout<<"000";
        }
    }else if(a!=c){
        cout<<"0000";
    }
    return 0;
}
