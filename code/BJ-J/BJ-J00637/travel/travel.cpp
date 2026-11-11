#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1,a2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    a1=s1[3]-'0';
    a2=s2[3]-'0';
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0] && s1[0]==s2[1]){
            cout<<1;
            if((a1<=3 && a2>=3)){
                cout<<1;
                if(abs(a1-a2)==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else if((a1==4 && a2==6)||a1==6 && a2==4){
                cout<<1<<1;
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}