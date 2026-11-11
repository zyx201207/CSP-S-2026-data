#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m,a[200005],ans=-1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j]&a[i]>ans && j!=i){
                    ans=a[j];
            }
        }
    }
    return 0;
}
