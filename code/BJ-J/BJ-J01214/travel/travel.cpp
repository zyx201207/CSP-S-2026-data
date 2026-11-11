#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int k1,k2;
int r1,r2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    r1=c1[0]*10+c1[1];
    r2=c2[0]*10+c2[1];
    if(r1!=r2){
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<s1.size();i++){
        if(isdigit(s1[i])){
            k1*=10;
            k1+=s1[i]-'0';
        }
    }
    for(int i=0;i<s2.size();i++){
        if(isdigit(s2[i])){
            k2*=10;
            k2+=s2[i]-'0';
        }
    }
    if(k1!=k2){
        cout<<"1000";
        return 0;
    }
    if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C')){
        cout<<"1100";
        return 0;
    }
    if(s1[2]<'D'&&abs(s1[2]-s2[2])>1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
