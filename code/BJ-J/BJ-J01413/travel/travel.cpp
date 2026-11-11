#include<iostream>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3){
        cout<<"0000";
        return 0;
    }
    int f=0;
    for(int i=0;i<=1;i++){
        if(s2[i]!=s4[i]){
            f=1;
            break;
        }
    }
    if(f){
        cout<<"1000";
        return 0;
    }
    char a=s2[2],b=s4[2];
    if('A'<=a&&a<='C'){
        if('D'<=b){
            cout<<"1100";
            return 0;
        }
    }
    if(a>='D'){
        if('A'<=b&&b<='C'){
            cout<<"1100";
            return 0;
        }else{
            cout<<"1111";
            return 0;
        }
    }
    if(a==b+1||b==a+1){
        cout<<"1111";
    }else{
        cout<<"1110";
    }
    return 0;
}
//OK
