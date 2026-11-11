#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
bool check(char a,char b){
    if(a=='A'){
        if(b=='B'||b=='C'){
            return 1;
        }
    }else if(a=='B'){
        if(b=='A'||b=='C'){
            return 1;
        }
    }else if(a=='C'){
        if(b=='B'||b=='A'){
            return 1;
        }
    }else if(a=='D'){
        if(b=='F'){
            return 1;
        }
    }else if(a=='F'){
        if(b=='D'){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
        if(check(s1[2],s2[2])){
            cout<<1;
            if(abs(s1[2]-s2[2])==1){
                cout<<1;
            }else{
                cout<<0;
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
    return 0;
}
