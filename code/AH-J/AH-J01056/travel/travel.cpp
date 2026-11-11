#include<bits/stdc++.h>
using namespace std;
string a,aa,b,bb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>aa>>b>>bb;
    if(a==b){
        cout<<1;
        int sa=(aa[0]-'0')*10+(aa[1]-'0'),sb=(bb[0]-'0')*10+(bb[1]-'0');
        if(sa==sb){
            cout<<1;
            char fa=aa[2],fb=bb[2];
            if('A'<=fa&&fa<='C'&&'A'<=fb&&fb<='C'){
                cout<<1;
                if(fa+1==fb||fb+1==fa){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else if('D'<=fa&&fa<='E'&&'D'<=fb&&fb<='E'){
                cout<<"11";
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}

