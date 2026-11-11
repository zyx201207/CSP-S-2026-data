#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int i,j,k,n,m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
        n=1;
    }
    if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
        m=1;
    }
    if(a1==b1){
        cout<<1;
        i=1;
    }
    else{
        cout<<0;
    }
    if(i&&a2[0]==b2[0]&&a2[1]==b2[1]){
        cout<<1;
        j=1;
    }
    else{
        cout<<0;
    }
    if(i&&j&&n==m){
        cout<<1;
        k=1;
    }
    else{
        cout<<0;
    }
    if(i&&j&&k&&(a2[2]-1==b2[2]||a2[2]+1==b2[2])){
        cout<<1;
    }
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
