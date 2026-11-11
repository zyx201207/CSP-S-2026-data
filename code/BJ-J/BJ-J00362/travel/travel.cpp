#include<bits/stdc++.h>
using namespace std;
int a[5];
char c1[5],c2[5];
char s1[5],s2[5];
int main(){
    freopen("travel.in","r",stdin);
    cin>>c1>>s1>>c2>>s2;
    freopen("travel.out","w",stdout);
    for(int i=0;i<2;i++){
        if(c1[i]==c2[i]) a[i]=2;
    }
    if(a[0]==a[1]&&a[0]==2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<2;i++){
        if(s1[i]==s2[i]) a[i]=1;
    }
    if(a[0]==a[1]&&a[0]==1) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(s1[2]<='C'&&s2[2]<='C') cout<<1;
    else if(s1[2]>'C'&&s2[2]>'C') cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(s1[2]-s2[2]==1||s2[2]-s1[2]==1) cout<<1;
    else cout<<"0";

}