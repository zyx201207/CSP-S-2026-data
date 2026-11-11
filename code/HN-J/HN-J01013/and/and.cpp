#include<bits/stdc++.h>
std using namespace;
int main(){
    freopen("add,in","r",stdin);
    freopen("add,out","w",stdout);
    int n,m,s=0;
    cin>>n>>m;
    int a[n+10];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i+1]>a[i]){
            s=a[i+1];
            a[i+1]=a[i];
            a[i]=s;
        }
    }
    cout<<a[s-1];
    return 0;
    }
