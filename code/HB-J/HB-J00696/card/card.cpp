#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
long long n,m,a[1001]={0},c[1001]={0},o=0;
cin>>n>>m;
for(int i=0; i<n; i++){
   cin>>a[i];
}
for(int i=0;i<n;i++){
    long long b[2001]={0};
    for(int j=i;j<n;j++){
        for(int k=0;k<n;k++){
            if(b[k]==a[j]){
                    b[k]=a[j];
                for(int f=j+1;j<n;j++){
                    b[f]=0;
                }
            }else {b[n+o]=a[j];
                      o++;}
        }}for(int t1=0;t1<n;t1++){
        for(int t2=0;t2<2001;t2++){
            if(a[t1]==b[t2]) c[a[t1]]++;
        }}
        }
for(int i=0;i<m;i++){
    if(c[a[i]]!=0) cout<<c[i+1];
}
return 0;
}

