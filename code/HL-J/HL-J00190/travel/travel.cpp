#include <bits/stdc++.h>
using namespace std;
int ans[4]={0,0,0,0};
string s11,s12,s21,s22;
int tc(char a,char b){
    if(a=='A'&&b=='B'||a=='A'&&b=='C'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='B'||a=='C'&&b=='A'||a=='D'&&b=='F'||a=='F'&&b=='D'){
        return 1;
    }else{
        return 0;
    }
}
int xl(char a,char b){
    if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='B'||a=='D'&&b=='F'||a=='F'&&b=='D'){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>s11>>s12>>s21>>s22;

    if(s11==s21){
        ans[0]=1;
    }
    if(s12[0]=s22[0]&&s12[1]==s22[1]&&ans[0]==1){
        ans[1]=1;
    }
    if(ans[1]==1&&tc(s12[2],s22[2])==1){
        ans[2]=1;
    }
    if(ans[2]==1&&xl(s12[2],s22[2])==1){
        ans[3]=1;
    }
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    return 0;

}
