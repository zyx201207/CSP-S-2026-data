#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,s=0;
    cin>>n>>m;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(a[i]+a[j]==a[i+j]) s+=1;

        }m-=1;
    }cout<<s;
}
