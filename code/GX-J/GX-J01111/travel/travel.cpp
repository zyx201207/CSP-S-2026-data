#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,s1,a,b;
    cin>>a>>s>>b>>s1;
    if(a==b){
        cout<<"1";
        if(s[0]==s1[0] && s[1]==s1[1]){
            cout<<"1";
            if( (s[2]<='C' && s1[2]<='C') || (('D'<=s[2] && s[2]<='F') && ('D'<=s1[2] && s1[2]<='F'))){
                cout<<"1";
                char t=s[2],c=s1[2];
                if(t==c+1 || t+1==c){
                    cout<<"1";
                }
                else {
                    cout<<"0"<<endl;
                    return 0;
                }
            }
            else {
                cout<<"00"<<endl;
                return 0;
            }
        }
        else {
            cout<<"000"<<endl;
            return 0;
        }
    }
    else {
            cout<<"0000"<<endl;
            return  0;
    }

    return 0;
}
