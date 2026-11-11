#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(b[1]==d[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if((b[1]=='A'||'B'||'C' && d[1]=='A'||'B'||'C')||(b[1]=='C'||'D' && d[1]=='C'||'D')){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
   
    if(b[2]+1==d[2] || b[2]-1==d[2]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}