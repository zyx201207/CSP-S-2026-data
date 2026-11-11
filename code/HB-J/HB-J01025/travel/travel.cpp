#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="0000";
bool flag=false;
bool isce(){
    if((s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D')){
        flag=true;
        return true;
    }
    if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')){
        flag=true;
        return true;
    }
    if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))return true;
    return false;
}
int main(){
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
//    cout<<1<<endl;
    if(c1==c2){
        ans[0]='1';
//        cout<<s1<<endl;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
//            cout<<3<<endl;
            ans[1]='1';
//            cout<<3<<endl;
            if(isce()){
                ans[2]='1';
//                cout<<4<<endl;
                if(flag){
                    ans[3]='1';
//                    cout<<5<<endl;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
