#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    bool ans1=0,ans2=0,ans3=0,ans4=0;
    if(c1==c3){
        ans1=1;
    }
    if(c2[0]==c4[0] && c2[1]==c4[1] && ans1==1){
        ans2=1;
    }
    if((((c2[2]>'C') && (c4[2]>'C')) || ((c2[2]<'D') && (c4[2]<'D'))) && ans2==1){
        ans3=1;
    }
    if(!(((c2[2]=='C') && (c4[2]=='A')) || ((c2[2]=='A') && (c4[2]=='C'))) && ans3==1){
        ans4=1;
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
