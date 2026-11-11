#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[5],s1[5],c2[5],s2[5];
    cin>>c1>>s1>>c2>>s2;
    //cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2<<endl;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
            cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if(s1[2]=='D'||s2[2]=='D'){
                if(s1[2]=='F'||s2[2]=='F'){
                    cout<<"11";
                }else cout<<"00";
            }else if(s1[2]=='F'||s2[2]=='F') cout<<"00";
            else if(s1[2]=='B'||s2[2]=='B') cout<<"11";
            else cout<<"10";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
