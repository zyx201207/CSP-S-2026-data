#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
int a[300005];
int b[300005];
int c[300005];
int d[300005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=a[i];
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        for(int k=1;k<=j;k++){
            if(a[i]==c[k]){
                for(int h=k;h<=j;h++){
                    c[h]==0;
                }
                j-=k;
            }
        }
        c[j]=a[i];
    }
    for(int j=1;j<=m;j++){
        for(int k=1;k<=n-i;k++){
            if(c[k]==j){
                d[i]++;
            }
        }
    }
    for(int j=1;j<=n;j++){
        a[j]=b[j];
    }
}
for(int i=1;i<=n;i++){
    cout<<d[i]<<" ";
}
return 0;
}

