#include<bits/stdc++.h>
using namespace std;
int n;
char   a[100000005];
char   b[100000005];
unsigned long long   c[100000005];
int tot=0;
int g=0;
int f;
int ans=0;
int main(){

freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>c[i]>>b[i];
    tot+=c[i];
}
for(int i=1;i<=n;i++){
     f+=c[i];
    for(int j=g;j<=tot;j++){
        if(j<=f){
        a[j]=b[i];
        g++;
        }
    }
}

for(int i=1;i<=tot/2;i++){
    if(a[i]!=a[tot+1-i]) ans+=1;
}
cout<<ans;
   return 0;
}
