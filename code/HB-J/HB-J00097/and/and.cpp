#include<bits/stdc++.h>
using namespace std;
int num1(int x){
    int y;
    while(!x){
        y+=x%2;
        x/=2;
    }
    return y;
}
long long ans=pow(2,20)-1;
int n,m,l=0,x=0;
int a[200005],maxn[200005];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mx<num1(a[j])){
                mx=num1(a[j]);
                l=j;
            }
        }
        maxn[x]=a[l];
        a[l]=0;
        x++;
    }
    for(int i=0;i<x;i++){
        ans=ans&a[i];
    }
    cout<<ans;
}
