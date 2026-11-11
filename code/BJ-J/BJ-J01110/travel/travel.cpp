#include <bits/stdc++.h>
using namespace std;
string s[3];
int c[3],is[5]={0},tmp[3];
char zi[3];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
        cin>>c[i]>>s[i];
    }if(c[1]==c[2]) {cout<<"1";}
    else {cout<<"0000";return 0;}
    for(int i=0;i<=s[1].size();i++){
        if(s[1][i]<='F'&&s[1][i]>='A'){
            zi[1]=s[1][i];
            break;
        }tmp[1]*=10;
        tmp[1]+=s[1][i]-'0';
    }for(int i=0;i<=s[2].size();i++){
        if(s[2][i]<='F'&&s[2][i]>='A'){
            zi[2]=s[2][i];
            break;
        }tmp[2]*=10;
        tmp[2]+=s[2][i]-'0';
    }if(tmp[1]==tmp[2]) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }if(zi[1]<='C'&&zi[1]>='A'&&zi[2]<='C'&&zi[2]>='A'){
        if(zi[1]+1==zi[2]||zi[2]+1==zi[1]){
            cout<<"11";
            return 0;
        }cout<<"10";
    }else if(zi[1]>='D'&&zi[1]<='F'&&zi[2]<='F'&&zi[2]>='D'){
        if(zi[1]+2==zi[2]||zi[2]+2==zi[1]){
            cout<<"11";
            return 0;
        }
        cout<<"10";
    }else {
        cout<<"00";
        return 0;
    }fclose(stdin);
    fclose(stdout);
    return 0;
}