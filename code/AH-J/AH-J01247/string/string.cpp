#include<bits/stdc++.h>
using namespace std;
string z;
char a;
int b,n,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>b>>a;
        c+=b;
        for(int j=0;j<=b;j++){
            z+=a;
        }
    }
    if(c%2==1){
        c/=2;
        int e;
        for(int i=0,j=2c+1;i<c;i++,j--){
            if(z[i]!=z[j]) e++;
        }
        cout<<e;
    }
    else{
        c/=2;
        int e;
        for(int i=0,j=2c;i<c;i++,j--){
            if(z[i]!=z[j]) e++;
        }
        cout<<e;
    }
    return 0;
}
//fang wei @)!#)@@!
