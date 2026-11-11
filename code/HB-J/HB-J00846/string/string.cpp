#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int a,b[7000000],v=0,g;
    char c[7000000],d[70000000];
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b[i]>>c[i];
    }
    for(int i=a-1;i>=0;i++){
        d[v]=c[i];
        v++;
    }
    if(d==c){
        cout<<"0";
        return 0;
    }
    sort(b[0],b[a-1]);
    g=a/2;
    cout<<g^b[0];
    return 0;
}
