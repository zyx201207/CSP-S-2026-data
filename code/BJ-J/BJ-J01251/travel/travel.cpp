#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    bool z=0,x=0,c=0,v=0;
    cin>>a>>b>>c>>d;
    if(a==c){
        z=1;
    }
    if(b[0]==d[0]&&b[1]==d[1]){
        x=1;
    }if(b[2]-d[2]='1'||d[2]-b[2]=='1'){
        c=1;
        if((b[2]=="C"||d[2]=="C")&&(b[2]=="D"&&d[2]=="D")){
            v=0;
        }
        else{
        v=1;
        }
    }
    cout<<z<<x<<c<<v;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
