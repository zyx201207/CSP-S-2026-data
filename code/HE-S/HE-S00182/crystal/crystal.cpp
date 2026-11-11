#include <bits/stdc++.h>
using namespace std;
int a[500005]={0};
int b[500005]={0};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,cnt=0;
    int e=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];}
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int o=a[j];
                a[j]=a[j+1];
                a[j+1]=o;
            }
        }
    }
    for(int i=0;i<=n-1;i++){
        int m1=m,i1=i;
        while(m1>=0&&i1<n){
            m1=m1-(i1+1)*(a[i1+1]-a[i1]);
            b[i]+=1;
            i1++;}
        if(m1<0){
            b[i]-=1;
            }
    }
    for(int i=0;i<n-1;i++){
        e=max(e,b[i]);}
    cout<<e+1;
return 0;}
