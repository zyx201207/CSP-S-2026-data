#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]=='0')c1.erase(0,1);
    if(c2[0]=='0')c2.erase(0,1);
    if(s1[0]=='0')s1.erase(0,1);
    if(s2[0]=='0')s2.erase(0,1);
    if(stoi(c1)!=stoi(c2)){
        cout<<"0000"<<endl;
    }else{
        cout<<1;
        if(stoi(s1.substr(0,s1.size()-1))!=stoi(s2.substr(0,s2.size()-1))){
            cout<<"000"<<endl;
        }else{
            cout<<1;
            s1.erase(0,s1.size()-1);
            s2.erase(0,s2.size()-1);
            if(s1[0]<='C' && s2[0]>'C' || s1[0]>'C' && s2[0]<='C'){
                cout<<"00"<<endl;
            }else{
                cout<<1;
                if(abs(s1[0]-s2[0])==1){
                    cout<<1<<endl;
                }else{
                    cout<<0<<endl;
                }
            }
        }
    }

    return 0;
}
//Trick||Treat!
