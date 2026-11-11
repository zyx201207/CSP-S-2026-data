#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int a,c;
string b,d;
cin>>a>>b>>c>>d;
if(a==c){
    cout<<1;
    if(b[0]==d[0]&&b[1]==d[1]){
        cout<<1;
        char x=b[2],y=d[2];
        if((x<='c'&&y<='c')||(x>'c'&&y>'c')){
            cout<<1;
            if(abs(x-y)==1)cout<<1;
            else cout<<0;
            }
        else cout<<0<<0;
        }
    else cout<<0<<0<<0;
    }
else cout<<0<<0<<0<<0;
return 0;
}
