#include<bits/stdc++.h>
using namespace std;
string s[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s[0]>>s[1]>>s[2]>>s[3];
    int died=0;
    if(s[0]==s[2]){
        if(s[1][0]==s[3][0]&&s[1][1]==s[3][1]){
            for(int i=0;i<=4;i++){
                if(s[1][2]=='A'+i){
                    for(int j=i-1;j<=i+1;j+=2){
                        if(s[3][2]=='A'+j&&!(s[3][2]=='C'&&s[1][2]=='D'||s[3][2]=='D'&&s[1][2]=='C')){
                            cout<<"1111";
                            return 0;
                        }else if(s[3][2]=='C'&&s[1][2]=='D'||s[3][2]=='D'&&s[1][2]=='C'){
                            died=1;
                        }
                    }
                }
            }
            if(died==1){
                cout<<1100;
            }else{
                cout<<1110;
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
