#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    int x=b[0]-'0',y=d[0]-'0';
    int xp=b[1]-'0',sz=d[1]-'0';
    if(x!=y||xp!=sz){
        cout<<"1000";
        return 0;
    }
    int k=b[2]-'A'+1,q=d[2]-'A'+1;
    k=min(k,q);q=max(k,q);
    if(k<=3&&q>=4){
        cout<<"1100";
        return 0;
    }
    if(q-k!=1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}