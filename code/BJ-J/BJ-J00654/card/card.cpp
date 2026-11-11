#include<bits/stdc++.h>
using namespace std;
int b[10005];
int where;
int findk(int x){
    for(int i=0;i<10005;i++){
        if(b[i]==x){
        where=i;
        return 1;
        }
    }
    return 0;
}
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
int a[n];
int DP[m]={0};
for(int i=0;i<n;i++){
cin>>a[i];
}
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        b[j]=a[j];
        if(findk(a[j])){
            for(int k=where;k<j;k++){
                b[k]=0;
            }
        b[j]=a[j];
        }
    }
    for(int j=0;j<10005;j++){
        if(b[j]!=0){
            DP[b[j]]++;
        }
    }
}
for(int i=0;i<m;i++){
    cout<<DP[i]<<" ";
}
return 0;
}
