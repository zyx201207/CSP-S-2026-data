#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int main(){
    cin>>n>>m;
    int a[n];
    for(int j=0;j<n;j++){
        cin>>a[j];
    }
    for(int i=0;i<n;i++){
        for(int o=0;o<n;o++){
            if(a[o+1]<a[o]){
                p=a[o];
                a[o]=a[o+1];
                a[o+1]=p;
            }
        }
    }
    cout<<a[m-1];
    return 0;
}
