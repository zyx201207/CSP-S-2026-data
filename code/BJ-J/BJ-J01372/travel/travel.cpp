#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,a1,b,b1;
    cin>>a>>a1>>b>>b1;
    int ans[4]={};
    if(a==b){
        ans[0]=1;
    }
    if(ans[0]==1){
    if(a1[0]==b1[0]&&a1[1]==b1[1]){
        ans[1]=1;
    }
    }
    if(ans[1]==1){
    if((a1[2]=='D'||a1[2]=='E')&&(b1[2]=='D'||b1[2]=='E')){
        ans[2]=1;
    }
    if(a1[2]>='A'&&a1[2]<='C'&&b1[2]>='A'&&b1[2]<='C'){
        ans[2]=1;
    }
    }
    int a1n=a1[2]-'A';
    int b1n=b1[2]-'A';
    if(ans[2]==1){
    if(a1n+1==b1n||a1n-1==b1n){
        ans[3]=1;
    }
    }
    for(int i=0;i<=3;i++){
        cout<<ans[i];
    }
    return 0;
}
