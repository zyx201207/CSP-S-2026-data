#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,an[1000]={};
    cin>>n;
    int a[10000];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                an[i]=a[i]&a[j];
            }
        }
    }
    cout<<an[1];
    return 0;
}
