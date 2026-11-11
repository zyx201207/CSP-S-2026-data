#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string2.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,co=0,a[1005];
    char c[1005];
    string b,x,y;
    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i]>>c[i];}
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            b+=c[i];
        }
    }
    int len=b.size();
    for(int i=0;i<len/2;i++)x+=b[i];
    for(int i=len/2+1;i<len;i++)y+=b[i];
    if(x==y){
        cout<<co;
        return 0;
    }

    return 0;
}
