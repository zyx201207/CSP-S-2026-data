#include<bits/stdc++.h>
using namespace std;
bool check_1(string a,string b){
    if(a==b) return true;
    else return false;
}
bool check_2(string a,string b,string x,string y){
    if(check_1(x,y)){
        if(a[0]==b[0] && a[1]==b[1]) return true;
        else return false;
    }
    else return false;
}
bool check_3(string a,string b,string x,string y){
    if(check_2(a,b,x,y)){
        if(a[2]=='A' || a[2]=='B' || a[2]=='C'){
            if(b[2]=='A' || b[2]=='B' || b[2]=='C') return true;
            else return false;
        }
        if(a[2]=='D' || a[2]=='F'){
            if(b[2]=='D' || b[2]=='F') return true;
            else return false;
        }
    }
    else return false;
}
bool check_4(string a,string b,string x,string y){
    if(check_3(a,b,x,y)){
        if(a[2]=='D' || a[2]=='F'){
            if(b[2]=='D' || b[2]=='F') return true;
            else return false;
        }
        else{
            if(a[2]=='A'){
                if(b[2]=='B'){
                    return true;
                }
                else return false;
            }
            else if(a[2]=='B'){
                if(b[2]=='A' || b[2]=='C'){
                    return true;
                }
                else return false;
            }
            else if(a[2]=='C'){
                if(b[2]=='B'){
                    return true;
                }
                else return false;
            }
        }
    }
    else return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool q1,q2,q3,q4;
    q1=check_1(c1,c2);
    q2=check_2(s1,s2,c1,c2);
    q3=check_3(s1,s2,c1,c2);
    q4=check_4(s1,s2,c1,c2);
    string ans;
    for(int i=0;i<4;i++){
        if(i==0){
            if(q1) ans[i]='1';
            else ans[i]='0';
        }
        if(i==1){
            if(q2) ans[i]='1';
            else ans[i]='0';
        }
        if(i==2){
            if(q3) ans[i]='1';
            else ans[i]='0';
        }
        if(i==3){
            if(q4) ans[i]='1';
            else ans[i]='0';
        }
    }
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
