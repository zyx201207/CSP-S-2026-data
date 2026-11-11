#include<iostream>
#include<string>
using namespace std;

int r1,s1;
string r2,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>s1>>s2;
    for(int i=0;;i++){
        if(r1==s1){
            if(r2[0]==s2[0]&&r2[1]==s2[1]){
                    if((r2[2]>='A'&&r2[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')){
                        if(r2[2]-1==s2[2]||r2[2]+1==s2[2]){
                            cout<<1111;
                            break;
                        }else{
                            cout<<1110;
                            break;
                        }
                    }else if((r2[2]>='C'&&r2[2]<='D')&&(s2[2]>='C'&&s2[2]<='D')){
                        cout<<1111;
                        break;
                    }else{
                        cout<<1100;
                        break;
                    }
            }else{
                cout<<1000;
                break;
            }
        }else{
            cout<<0000;
            break;
        }
    }

    return 0;
}
