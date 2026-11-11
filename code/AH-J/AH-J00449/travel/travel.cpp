#include<iostream>
using namespace std;
long long a,b,c,d;
char e,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>e>>c>>d>>f;
    if(a!=c){
        cout<<"0000";
    }
    else{
        cout<<"1";
        if(b!=d){
            cout<<"000";
        }
        else{
            cout<<"1";
            if(e<='C'&&f<='C'||e>='D'&&f>='D'){
                cout<<"1";
                if(min(e,f)+1==max(e,f)){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
    }
    return 0;
}
