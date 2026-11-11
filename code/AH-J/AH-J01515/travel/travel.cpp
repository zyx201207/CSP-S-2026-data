#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,c,d,s,t;
char m,n;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b>>c>>d;
    s=b[0];s+=b[1];
    t=d[0];t+=d[1];
    m=b[2];
    n=d[2];
    if(a==c){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(s==t){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(('A'<=m&&m<='C'&&'A'<=n&&n<='C')||(m=='D'&&n=='F')||(m=='F'&&n=='D')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(m=='D'&&n=='F'||m=='F'&&n=='D'){
        cout<<1;
    }else if(('A'<=m&&m<='C'&&'A'<=n&&n<='C')&&(n==m+1||m==n+1)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
