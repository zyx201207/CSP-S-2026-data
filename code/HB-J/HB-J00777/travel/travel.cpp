#include<bits/stdc++.h>
using namespace std;

int main(){
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
string a,b,c,d;
cin>>a>>b>>c>>d;
int x=0;
if(a.size()!=c.size())cout<<0;
    else{
        for(int i=1;i<=a.size();i++){
            if(a[i]!=c[i]){
                cout<<0;
                    x=1;
                    break;
}
}
}
if(x==1){
    cout<<0<<0<<0;
    return 0;
}
else cout<<1;
if(b[0]==d[0]&&b[1]==d[1])cout<<1;
else cout<<0;
int cnt=0;
if(b[2]<='C'&&d[2]<='C')cnt=1;
if(b[2]>='D'&&d[2]>='D')cnt=1;
if(b[0]==d[0]&&b[1]==d[1]&&cnt==1)cout<<1;
else cout<<0;
if(b[0]==d[0]&&b[1]==d[1]){
        if(b[2]=='C'&&d[2]=='D'||d[2]=='C'&&b[2]=='D'){
            cout<<0;
            return 0;
        }
if(abs(b[2]-d[2])==1)cout<<1;
else cout<<0;
}
else cout<<0;
cout<<LONG_MAX;
return 0;
}
