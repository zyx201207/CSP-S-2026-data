#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("traval.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<1;
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            cout<<1;
            char x=a2[2],y=b2[2];
            if((x=='D'&&y=='F')||(x=='D'&&y=='F')){
                cout<<11;
            }else if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
                cout<<1;
                if(abs(x-y)==1)cout<<1;
                else cout<<0;
            }else cout<<"00";
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
