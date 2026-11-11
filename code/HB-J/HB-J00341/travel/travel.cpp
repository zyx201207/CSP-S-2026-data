#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string a,b;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>a>>c2>>b;
if(c1==c2){
    cout<<1;
    if(a[0]==b[0]&&a[1]==b[1]){
        cout<<1;
        if(max(a[2],b[2])<='C'||min(a[2],b[2])>='D'){
            cout<<1;
            if(max(a[2],b[2])-1==min(a[2],b[2]))cout<<1;
            else cout<<0;
        }
        else cout<<"00";
    }
    else cout<<"000";
}
else cout<<"0000";
return 0;
}
