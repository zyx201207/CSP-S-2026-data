#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
string s,s1,c,c1;
cin>>s>>s1>>c>>c1;
if(s==c){
    cout<<'1';
    string v,v1;
    v+=s1[0];
    v+=s1[1];
    v1+=c1[0];
    v1+=c1[1];
    if(v==v1){
        cout<<'1';
        if((s1[2]>='A'&&s1[2]<='C'&&c1[2]>='A'&&c1[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&c1[2]>='D'&&c1[2]<='F')){
            cout<<'1';
            if(char(s1[2]+1)==c1[2]||char(c1[2]+1)==s1[2]||(s1[2]=='D'&&c1[2]=='F')||(c1[2]=='D'&&s1[2]=='F')){
                cout<<'1';
                return 0;
            }else{
                cout<<'0';
                return 0;
            }
        }else{
            cout<<"00";
            return 0;
        }
    }else{
        cout<<"000";
        return 0;
    }
}else{
    cout<<"0000";
    return 0;
}



return 0;
}
