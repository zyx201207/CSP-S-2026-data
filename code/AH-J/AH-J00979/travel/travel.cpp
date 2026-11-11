#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,s;
    cin>>a>>b>>c>>d;
    if(a==c&&a!="01"&&a!="16"){
        s+='1';
    }else{
        s+='0';
    }
    if(b[0]==d[0]&&b[1]==d[1]&&s[0]=='1'){
        s+='1';
    }else{
        s+='0';
    }
    if(s[1]=='1'){
        if((b[2]<'D'&&d[2]<'D')||(b[2]>='D'&&d[2]>='D')){
            s+='1';
        }else{
            s+='0';
        }
    }else{
        s+='0';
    }
    if(s[2]=='1'){
        int k=b[2]-d[2];
        if(abs(k)==1){
            s+='1';
        }else{
            s+='0';
        }
    }else{
        s+='0';
    }
    cout<<s;



    return 0;
}
