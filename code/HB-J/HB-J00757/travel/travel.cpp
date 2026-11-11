#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int res=1;
    if(a==c){
        cout<<1;
    }else{
        res=0;
        cout<<0;
    }
    int cnt=1;
    if(b[0]==d[0] && b[1]==d[1] && res!=0){
        cout<<cnt;
    }else{
        cnt=0;
        cout<<cnt;
    }
    int ans=1;
    for(char i='D';i<='F';i++){
        if(b[2]==i || d[2]==i){
            ans=0;
            break;
        }
    }
    if(cnt==0 || res==0){
        ans=0;
    }
    cout<<ans;
    if(abs((int)b[2]-(int)d[2])==1 && ans!=0 && cnt!=0 && res!=0){
        cout<<1;
    }else cout<<0;
    return 0;
}
