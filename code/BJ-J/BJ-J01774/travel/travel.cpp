#include<iostream>
#include<string>
using namespace std;
string c1,s1,c2,s2,p1,p2;
string h1,h2;
bool flag;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<3;i++){
       if(i<2){
            p1+=s1[i];
       }
       else{
            h1=s1[i];
       }
    }
    for(int i=0;i<3;i++){
       if(i<2){
            p2+=s2[i];
       }
       else{
            h2=s2[i];
       }
    }
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(p1==p2){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    if( ((h1[0]=='A' || h1[0]=='B' || h1[0]=='C') && (h2[0]=='A' || h2[0]=='B' || h2[0]=='C'))||((h1[0]=='D' || h1[0]=='F') && (h2[0]=='D' || h2[0]=='F' ))){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(h1[0]=='A' || h1[0]=='B' || h1[0]=='C'){
        flag=1;
    }else{
        flag=0;
    }
    if(flag==0){
        cout<<"1";
        return 0;
    }
    if(h1[0]=='B' || h2[0]=='B'){
        cout<<"1";
        return 0;
    }
    cout<<"0";
    return 0;
}
