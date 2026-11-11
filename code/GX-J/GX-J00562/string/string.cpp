#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,b[10005],m=1000000,d=1;
    char c,e;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i];
        cin>>c;
        if(c==e){
            d+=1;
        }
        e=c;
        if(b[i]<m){
            m=b[i];
        }
    }
    if(d==a){
        cout<<0;
        return 0;
    }
    m*=(a/2);
    cout<<m;
    return 0;
}
