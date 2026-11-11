#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int x,y,p,q;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }else{
        cout<<1;
    }
    x=s1[0]*10+s1[1];
    y=s2[0]*10+s2[1];
    if(x!=y){
        cout<<"000";
        return 0;
    }else{
        cout<<1;
    }
    if(s1[2]>='D'){
        p=1;
    }
    if(s2[2]>='D'){
        q=1;
    }
    if(p!=q){
        cout<<"00";
        return 0;
    }else{
        cout<<1;
    }
    if((abs(s1[2]-s2[2])==1&&p==0)||(p==1)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
