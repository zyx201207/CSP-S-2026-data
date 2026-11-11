#include<bits/stdc++.h>
using namespace std;
struct s{
    int a;
    string c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;

    cin<<n;
    s b[n];
    for(int i=0;i<n;i++){
        cin>> b[i].a>>b[i].c;
    }
    s d[n];
    for(int i=n;i>0;i--){
        for(int j=0;j<n;j++){
            d[i-1].c==b[j].c;
            d[i-1].a==b[j].a;}
    }
    int x;
    for(int i=0;i<n;i++){
        if(d[i].c!=b[i].c){
            if(d[i].a<=b[i].a){
                x=x+d[i].a;
            }
            if(d[i].a>b[i].a){
                x=x+b[i].a;
            }
        }
    }
    cout<<x;
    return 0;
}
