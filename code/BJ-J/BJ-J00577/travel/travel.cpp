#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool check1(string s1,string s2){
    if(s1 == s2) return true;
    return false;
}
bool check2(string s1,string s2,string s3,string s4){
    if(check1(s1,s2)==false) return false;
    int num1=0,num2=0,base=1;
    for(int i=1;i>=0;i--){
        num1+=base*s3[i];
        num2+=base*s4[i];
        base*=10;
    }
    if(num1==num2){
        return true;
    }
    return false;
}
bool check3(string s1,string s2,string s3,string s4){
    if(check2(s1,s2,s3,s4)){
        char c1=s3[2],c2=s4[2];
        if((c1=='F'&&c2=='D') || (c1=='D'&&c2=='F') || (c1=='C'&&c2=='B') || (c1=='B'&&c2=='C') || (c1=='B'&&c1=='A') || (c1=='A'&&c2=='B') || (c1=='C'&&c2=='A') || (c1=='A'&&c2=='C')){
            return true;
        }else{
            return false;
        }
    }
    return false;
}
bool check4(string s1,string s2,string s3,string s4){
    if(check3(s1,s2,s3,s4)){
        int num1,num2;
        int base=1;
        for(int i=1;i>=0;i--){
            num1+=base*s3[i];
            num2+=base*s4[i];
            base*=10;
        }
        char c1=s3[2],c2=s4[2];
        if(c1==c2){
            if(abs(num1-num2)==1){
                return true;
            }else{
                return false;
            }
        }
        else if(num1==num2){
            if((c1=='F'&&c2=='D') || (c1=='D'&&c2=='F') || (c1=='C'&&c2=='B') || (c1=='B'&&c2=='C') || (c1=='B'&&c1=='A') || (c1=='A'&&c2=='B')){
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}
int main(){
    freopen("travel.in","r".stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s1>>s3>>s2>>s4;//s1，s2表示车厢号，s3,s4表示座位
    string ans={};
    if(check1(s1,s2)){
        ans+='1';
    }else{
        ans+='0';
    }
    //cout<<ans<<" ";
    if(check2(s1,s2,s3,s4)){
        ans+='1';
    }else{
        //cout<<"feao";
        ans+='0';
    }
    //cout<<ans<<" ";
    if(check3(s1,s2,s3,s4)){
        ans+='1';
    }else{
        ans+='0';
    }
    //cout<<ans<<" ";
    if(check4(s1,s2,s3,s4)){
        ans+='1';
    }
    else{
        ans+='0';
    }
    cout<<ans;
    return 0;
}