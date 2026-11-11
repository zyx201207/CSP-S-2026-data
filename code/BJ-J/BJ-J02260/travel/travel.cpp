#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)ans[1]=1;
    if(b[0]==d[0]&&b[1]==d[1]&&ans[1]==1)ans[2]==1;
    if(ans[2]==1){
        if(b[2]=='A'&&d[2]=='B')ans[4]=1;
        if(b[2]=='A'&&d[2]=='C')ans[3]=1;
        if(b[2]=='B'&&d[2]=='A')ans[4]=1;
        if(b[2]=='B'&&d[2]=='C')ans[4]=1;
        if(b[2]=='C'&&d[2]=='B')ans[4]=1;
        if(b[2]=='C'&&d[2]=='A')ans[3]=1;
        if(b[2]=='D'&&d[2]=='F')ans[4]=1;
        if(b[2]=='F'&&d[2]=='D')ans[4]=1;
    }
    if(ans[4]==1){
    cout<<"1111";
    return 0;
    }
    for(int i=1;i<=4;i++){
    cout<<ans[i];
    }
return 0;
}