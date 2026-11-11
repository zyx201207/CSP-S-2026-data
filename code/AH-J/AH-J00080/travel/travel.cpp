#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;int l=0,r = 0;
int main(){
    /*freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);*/
    cin>>c1>>s1>>c2>>s2;
    if((s1[2] == 'D'&&s2[2]== 'F')||(s1[2] == 'A'&&s2[2]== 'C')){
        r = 1;
    }
    if((s1[2] == 'F'&&s2[2]== 'D')||(s1[2] == 'C'&&s2[2]== 'A')){
        r = 1;
    }
    if(c1 == c2){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0] == s2[0]&&s1[1] == s2[1]){
        cout<<"1";
        l = 1;
    }
    else{
        cout<<"0";
    }
    if((l == 1 && r == 1)||((s1[2] != 'D'&&s2[2] != 'D')&&(s1[2]!='F'&&s2[2] != 'F'))){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(l == 1&&(abs(int(s1[2]-s2[2])) == 1||r == 1)){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
