#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ck1(string a,string b){
    for(int i=0;i<2;i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}
int ck2(string a,string b){
    if(a[0]!=b[0]||a[1]!=b[1]) return 0;
    return 1;
}
int ck3(string a,string b){
    int ok1=0,ok2=0;
    if(a[2]>'C') ok1=1;
    if(b[2]>'C') ok2=1;
    if(ok1==ok2) return 1;
    return 0;
}
int ck4(string a,string b){
    if(abs((a[2]-'0')-(b[2]-'0'))==1) return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>b>>c>>d;
    if(!ck1(a,c)){
        cout<<"0000";return 0;
    }
    if(!ck2(b,d)){
        cout<<"1000";return 0;
    }
    if(!ck3(b,d)){
        cout<<"1100";return 0;
    }
    if(!ck4(b,d)){
        cout<<"1110";return 0;
    }
    else cout<<"1111";
    return 0;
}
