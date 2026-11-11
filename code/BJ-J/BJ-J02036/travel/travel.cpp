#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

int a,b;
string c,d;
cin>>a>>c>>b>>d;
if(a=b){
    cout<<1;
     if(c[1]==d[1] && c[2]==d[2]){
    cout<<1;

 if(((c[3]=='A'||c[3]=='B'||c[3]=='C')&&(d[3]=='A'||d[3]=='B'||d[3]=='C'|| )) || ((c[3]=='D'||c[3]=='E')&&(d[3]=='D'||d[3]=='E'))){
        cout<<1;
        if(((c[3]=='D'||c[3]=='E')&&(d[3]=='D'||d[3]=='E'))||((c[3]=='A'||c[3]=='B')&&(d[3]=='A'||d[3]=='B'))||((c[3]=='B'||c[3]=='C')&&(d[3]=='B'||d[3]=='C'))){
            cout<<1;
        }else{
    cout<<0;
    return 0;
    }
    }else{
    cout<<"00";
    return 0;
    }
}else{
cout<<"000";
return 0;
}


}else{
cout<<"0000";
}






return 0;
}
