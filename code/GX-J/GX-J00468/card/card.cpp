#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[500000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        i+=i-1;
    }
    return 0;
}
