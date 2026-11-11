#include<bits/stdc++.h>
using namespace std;
string a,b;
int a1,b1;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
    cin>>a1>>a>>b1>>b;
    if(a1!=b1){
        cout<<"0000";
        return 0;
    }else if(a[1]==b[1]&&a[0]==b[0]){
        cout<<"11";
    }else{
        cout<<"1000";
        return 0;
    }
    if((a[2]<='C'&&b[2]>'C')||(b[2]<='C'&&a[2]>'C')){
        cout<<"00";return 0;
    }else{
        cout<<"1";
    }
    if(int(a[2]+1)==int(b[2])||int(b[2]+1)==int(a[2])){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
