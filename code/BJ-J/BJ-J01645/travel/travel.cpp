#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            int k1,k2;
            if(s1[2]>='A'&&s1[2]<='C') k1=1;
            else k1=2;
            if(s2[2]>='A'&&s2[2]<='C') k2=1;
            else k2=2;
            if(k1==k2){
                cout<<1;
                if(k1==2){
                    cout<<1;
                }else{
                    if(abs((int)s1[2]-(int)s2[2])==1){
                        cout<<1;
                    }else{
                        cout<<"0";
                    }
                }
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
