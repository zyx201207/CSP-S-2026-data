#include<bits/stdc++.h>
using namespace std;
int n,m;
string tentotwo(int a){
    string abc;
    int b[1000],t=1;
    while(a>0){
        b[t]=a%2;
        a/=2;
        t++;
    }
    for(int i=t;i>=1;i--){
        abc+=b[i];
    }
    return abc;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    int a,b,c,m1=0,m2;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        int c;
        cin>>c;
        if(c>=m1){
            m2=m1;
            m1=c;
        }
    }
    cout<<m2<<endl;
}
