#include <bits/stdc++.h>
using namespace std;
int n,b[200001],c,o,v;
char a[200001],s[99999999],x[99999999],u[99999999];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i];
        cin>>a[i];
    }
    int e=0;
    for(int j=0;j<n;j++){for(int k=0;k<b[j];k++){s[e]=a[j];e++;}}
    e-=1;
        for(int p=e;p>=0;p--) {x[p]=s[v];v++;}
    for(int w=0;w<e+e;w++){

        c=0;
        v=0;
        for(int y=e;y>=0;y--) {u[y]=x[v];v++;}
        for(int r=0;r<=e;r++){if(u[r]==x[r])c++;}
        if(c==e+1){cout<<o;return 0;}
        if(x[e-o]!=s[e-o])x[e-o]=s[e-o];

         o++;}


return 0;}

