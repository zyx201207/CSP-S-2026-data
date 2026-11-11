#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char a3,b3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>a3;
    cin>>b1>>b2>>b3;
    if(a1==b1){
        cout<<1;
        if(a2==b2){
            cout<<1;
            if((a3<='C'&&b3<='C')||(a3>'C'&&b3>'C')){
                cout<<1;
                if(max(int(a3),int(b3))-min(int(a3),int(b3))==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else {
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
