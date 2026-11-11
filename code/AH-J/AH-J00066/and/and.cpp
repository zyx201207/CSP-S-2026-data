#include<bits/stdc++.h>
using namespace std;

int main(){
    preopen(and.in,"r",stdin);
    preopen(and.out,"w",stdout);
    int n,m,a[200005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<i-1;j++){
            if(a[j]<a[j+1]){
                sort(a[j],a[j+1]);
            }
        }
    }
    cout<<a[2];
    return 0;
}
