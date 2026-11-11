#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int a=0,b=0,c=0,d=0;
    cin>>c1>>s1>>c2>>s2;
    if('c1'-'0'=='s1'-'0'){
        a=1;
    }
    if(('c2[0]'-'0')*10+('c2[1]'-'0')==('s2[0]'-'0')*10+('s2[1]'-'0')){
        b=1;
    }
    if(('c2[2]'-'A'<3&&'s2[2]'-'A'<3)||('c2[2]'-'D'<2&&'s2[2]'-'D'<2)){
        c=1;
    }
    if('c2[2]'-'A'-('s2[2]'-'A')==1||'c2[2]'-'A'-('s2[2]'-'A')==-1){
        d=1;
    }
    cout<<a<<b<<c<<d;
    fclose(stdin);
    fclose(stdout);
    return 0;
}