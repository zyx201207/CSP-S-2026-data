#include<bits/stdc++.h>
using namespace std;
bool ans[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans[0]=1;
    }
    bool pai=1;
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            pai=0;
            break;
        }
    }
    if(pai&&ans[0]){
        ans[1]=1;
    }
    char a=s1[2],b=s2[2];

    if((a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C')||(b=='A'&&a=='B')||(b=='A'&&a=='C')||(b=='B'&&a=='C')||(a=='D'&&b=='E')||(a=='E'&&b=='D')){
        if(ans[1]==1){
            ans[2]=1;
        }
    }
    if(a=='A'&&b=='B'||a=='B'&&b=='C'||a=='D'&&b=='E'||b=='A'&&a=='B'||b=='B'&&a=='C'||b=='D'&&a=='E'){
        if(ans[2]==1){
            ans[3]=1;
        }
    }
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    return 0;
}
