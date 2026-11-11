#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f[200];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    f['A'-'0']=f['B'-'0']=f['C'-'0']=1;
    f['D'-'0']=f['F'-'0']=2;
    if(a==c){
        if(b[0]==d[0]&&b[1]==d[1]){
            if(f[b[2]-'0']==f[d[2]-'0']){
                if(b[2]-'0'+1==d[2]-'0'||b[2]-'0'-1==d[2]-'0'){
                    if(b[2]=='C'&&d[2]=='D'||b[2]=='D'&&d[2]=='C') cout<<1110;
                    else cout<<1111;
                }
                else cout<<1110;
            }
            else cout<<1100;
        }
        else cout<<1000;
    }else cout<<"0000";
    return 0;
}
