#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long ch[6]={0,1,1,1,2,2};
string c,d,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<"1";
        if(c[0]==d[0]&&c[1]==d[1]){
            cout<<"1";
        }else{
            cout<<"000";
            return 0;
        }
        if(ch[c[2]-'A'+1]==ch[d[2]-'A'+1]){
            cout<<"1";
        }else{
            cout<<"00";
            return 0;
        }
        if(max(c[2],d[2])-min(c[2],d[2])==1&&max(c[2],d[2])!='D'&&min(c[2],d[2])!='C'){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    return 0;
}
