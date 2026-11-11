#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int cut(string str){
    int ten=str[0]-'0';
    int one=str[1]-'0';
    return ten*10+one;
}
bool together(char c,char d){
    if((c=='F'||c=='D')&&(d=='F'||d=='D')){
        return true;
    }else if((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C')){
        return true;
    }return false;
}
bool with(char c, char d){
    if((c=='F'&&d=='D')||(c=='D'&&d=='F')) return true;
    else if(c=='B'){
        if(d=='A'||d=='C') return true;
    }else if(d=='B'){
        if(c=='A'||c=='C') return true;
    }return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(cut(s1)==cut(s2)){
            cout<<1;
            if(together(s1[2],s2[2])){//p
                cout<<1;
                if(with(s1[2],s2[2])) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
}
