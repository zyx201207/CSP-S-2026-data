#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1,s1[3],c2,s2[3];
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&c1!=("01"||"16")){
        cout<<"1";

    }else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    char m="A"||"B"||"C";
    char n="A"||"B"||"C";
    char t="D"||"E";
    char y="D"||"E";
    if((s1[2]==m&&s2[2]==n)||(s1[2]==t&&s2[2]==y)){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if((s1[2]+1==s2[2]&&s1!="C")||(s1[2]-1==s2[2]&&s1!="D")){
        cout<<"1";
    }else{
        cout<<"0";
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

