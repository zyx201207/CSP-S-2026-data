#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool oss(char a, char b){
    if((a=='A' || a=='B' || a=='C') && (b=='A' || b=='B' || b=='C'))return true;
    if((a=='D' || a=='E') && (b=='D' || b=='E')) return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        printf("1");
    }
    else{
        printf("0");
    }
    if(c1==c3 && c2.substr(0,2)==c4.substr(0,2)){
        printf("1");
    }
    else{
        printf("0");
    }
    if(c1==c3 && c2.substr(0,2)==c4.substr(0,2) && oss(c2[2],c4[2])){
        printf("1");
    }
    else{
        printf("0");
    }
    if(c1==c3 && c2.substr(0,2)==c4.substr(0,2) && oss(c2[2],c4[2]) && abs(c2[2]-c4[2])==1){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0;
}
