#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string6.in","r",stdin);
freopen("string6.out","w",stdout);
long long n,a[10000],e=0,g=0;
string b[10000],c,d,f;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
}


for(int i=1;i<=n;i++){
    for(int j=1;j<=a[i];j++){
        c+=b[i];
    }
}
for(int i=c.size();i>=0;i--){
    d+=c[i];
}
if(d.size()%2==0){
    for(int i=0;i<d.size()/2;i++){
        f+=d[i];
    }
    for(int i=0;i<d.size()/2;i++){
        if(c[i]!=f[i]){
            e++;
        }
    }
}
else{
    for(int i=0;i<(d.size()+1)/2;i++){
        f+=d[i];
    }
    for(int i=0;i<(d.size()+1)/2;i++){
        if(c[i]!=f[i]){
            e++;
        }
    }
}

cout<<e;

return 0;
}
