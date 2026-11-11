#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+10]={0},s[n+10]={0},z=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        z=max(z,a[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]==z) a[i]==0;
    }
    for(int i=0;i<n;i++){
        z=max(z,a[i]);
    }
    cout<<z;
    return 0;
}
