#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s1,s2;
    int c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]*10+s1[1]*10==s2[0]*10+s2[1]){
            cout<<1;
            if((s1[2]<='C'&&s2[2]<='C'&&s1[2]!=s2[2])||(s1[2]<='F'&&s2[2]<='F'&&s1[2]>='D'&&s2[2]>='D'&&s2[2]!=s1[2])){
                cout<<1;
                if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
                    cout<<1;
                }else if(s2[2]>='D'&&s1[2]>='D'){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<00;
            }
        }else{
            cout<<000;
        }
    }else{
        cout<<0000;
    }
    return 0;
}
