#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
  if(a!=b){
    return a>b;
  }
  return a<b;
}
int main(){
    int m,n,a[100000005],cnt=0;
    cin>>m>>n;
    freopen("crystal.in","w",stdin);
    freopen("crystal.out","r",stdout);
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int b=ceil(m/2);
    int h=a[b];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[h-i]+i==a[h-j]+j && i+j==h){
                a[h-i]+=i;
                a[h-j]+=j;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(a[i]==a[h]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
