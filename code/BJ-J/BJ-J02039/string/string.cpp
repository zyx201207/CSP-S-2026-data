#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
int a[n+1];
char b[n+1];
for(int i=1;i<=n;++i){
    cin>>a[i];
    cin>>b[i];
}
int cnt=0;
for(int i=1;i<=n;++i){
    cnt+=a[i];
}
char c[cnt+1];
int t=0;
for(int i=1;i<=n;++i){
    for(int j=t+1;j<=a[i];++i){
        c[j]=b[i];
    }
    t+=a[i];
}
int f=0;
if(cnt%2==0){
    for(int i=1;i<cnt/2;++i){
        if(c[i]!=c[cnt+1-i]){
            f++;
        }
    }
}else{
    for(int i=1;i<(cnt+1)/2;++i){
        if(c[i]!=c[cnt+1-i]){
            f++;
        }
    }
}
cout<<f;
return 0;
}
