#include<bits/stdc++.h>
using namepsace std;
string a;
string b;
string c;
string d;
int main(){
    freopen("traval.in","r",stdin);
    freopen("traval.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<1;
            if(a[2]=='A'&&b[2]=='B'||a[2]=='A'&&b[2]=='C'||a[2]=='B'&&b[2]=='C'||a[2]=='D'&&b[2]=='E'||a[2]=='B'&&b[2]=='A'||a[2]=='C'&&b[2]=='A'||a[2]=='C'&&b[2]=='B'||a[2]=='E'&&b[2]=='D'){
                cout<<1;
                if(a[2]=='A'&&b[2]=='B'||a[2]=='A'&&b[2]=='C'||a[2]=='D'&&b[2]=='E'||a[2]=='B'&&b[2]=='A'||a[2]=='C'&&b[2]=='A'||a[2]=='D'&&b[2]=='E'){
                    cout<<1;}
                else{
                    cout<<0;}
            }
            else{
                cout<<00;}}
        else{
            cout<<000;}
    }
    else{
        cout<<0000;}
}
