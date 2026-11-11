#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c,c1,n=0,cnt,cnt2,true1=1;
    string s,s1,a="ABCDF";
    cin>>c>>s>>c1>>s1;
    if(c%10==c1%10&&c/10==c1/10) cout<<1;
    else {
        true1=0;
        cout<<0;
    }
    if(true1==1)
        if(s[0]==s1[0]&&s[1]==s1[1])cout<<1;
        else{
            cout<<0;
            true1=0;
        }
    else cout<<0;
    /*if(true1==1){
        if(n==1)cout<<1;
        else {
            cout<<0;
            true1=0;
        }
    }
    else cout<<0;*/
    for(int i=0;i<=4;i++){
        if(s[2]==a[i])cnt=i;
        if(s1[2]==a[i])cnt2=i;
    }
    if(true1==1){
        if(cnt<=2&&cnt2<=2)cout<<1;
        else if(cnt>2&&cnt2>2)cout<<1;
        else {
            true1=0;
            cout<<0;
        }
    }
    else {
        true1=0;
        cout<<0;
    }
    if(true1==1){
        if(cnt-1==cnt2||cnt+1==cnt2)cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
