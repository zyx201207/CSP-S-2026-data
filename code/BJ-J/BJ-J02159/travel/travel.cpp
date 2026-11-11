#include<bits/stdc++.h>
using namespace std;
int sa,sb,pa,pb;
string a,b;
int main(){
    freopen("travel.in","w",stdin);
    freopen("travel.out","r",stdout);
    cin>>sa>>a>>sb>>b;
    if(sa==sb)cout<<'1';
    else cout<<'0';
    pa=a[1]-'0';
    pb=b[1]-'0';
    if(pa==pb){
        cout<<'1';
        if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C')){
            cout<<'1';
            if((a[2]-b[2]==1)||(a[2]-b[2]==-1))cout<<'1';
            else cout<<'0';
        }
        else if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F')){
            cout<<'1';
            if((a[2]-b[2]==1)||(a[2]-b[2]==-1))cout<<'1';
            else cout<<'0';
        }
        else cout<<"00";
    }
    else{
        cout<<"00";
    }

    return 0;
}
