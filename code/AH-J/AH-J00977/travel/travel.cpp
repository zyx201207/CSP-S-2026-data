#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,s2,s3,s4;
    cin>>s>>s2>>s3>>s4;
    if(s==s3){
        cout<<1;
        string t,b;
        for(int i=0;i<2;i++){
            t=t+s2[i];
            b=b+s4[i];
        }
        if(t==b){
            cout<<1;
            if(s2[s2.size()-1]>='A' &&s2[s2.size()-1]<='C' &&s4[s4.size()-1]>='A' && s4[2]<='C' || s2[s2.size()-1]>='D' && s2[s2.size()-1]<='E' && s4[s4.size()-1]>='D'&&s4[s4.size()-1]<='E'){
                    cout<<1;
                    if(s2[2]==s4[2]+1 || s2[2]==s4[2]-1){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
