#include<iostream>
#include<cstring>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    long long z1,z2;
    cin>>z1>>s1>>z2>>s2;
    if(z1==z2){
        cout<<"1";
    }
    else cout<<"0";
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&z1==z2){
        cout<<"1";
    }
    else cout<<"0";
    char amin=min(s2[2],s1[2]);
    char amax=max(s2[2],s1[2]);
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&z1==z2&&amax<='C'&&amin>='A'||amax<='E'&&amin>='D'){
        cout<<"1";
    }
    else cout<<"0";
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&z1==z2&&amax==amin+1&&amin!='C'){
        cout<<"1";
    }
    else cout<<"0";
    cout<<endl;
    return 0;
}
