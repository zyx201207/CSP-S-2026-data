#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool check1(string a,string b){
    for(int i=0;i<=1;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
bool check2(string a,string b){
    if(b[2]=='D'){
        if(a[2]=='F'){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(b[2]=='F'){
            if(a[2]=='D'){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
                if(a[2]=='D'||a[2]=='F'){
                    return false;
                }
                else{
                        return true;
                }
            }
        }
    }
}
bool check3(string a,string b){
    int l=a[2]-'A';
    int d=b[2]-'A';
    if(abs(l-d)==1){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(check1(s1,s2)){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(check2(s1,s2)){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(check3(s1,s2)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
