#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char e,f;
    cin>>a>>b>>e>>c>>d>>f;
    if(a!=c){
        cout<<"0000";
    }
    else{
        if(b!=d){
            cout<<"1000";
        }
        else{
            if(e=='A'){
                if(f=='B'){
                    cout<<"1111";
                }
                else if(f=='C'){
                    cout<<"1110";
                }
                else{
                    cout<<"1100";
                }
            }
            if(e=='B'){
                if(f=='A'||f=='C'){
                    cout<<"1111";
                }
                else{
                    cout<<"1100";
                }
            }
            if(e=='C'){
                if(f=='B'){
                    cout<<"1111";
                }
                else if(f=='A'){
                    cout<<"1110";
                }
                else{
                    cout<<"1100";
                }
            }
            if(e=='D'){
                if(f=='E'){
                    cout<<"1111";
                }
                else{
                    cout<<"1100";
                }
            }
            if(e=='E'){
                if(f=='D'){
                    cout<<"1111";
                }
                else{
                    cout<<"1100";
                }
            }
        }
    }
    return 0;
}
