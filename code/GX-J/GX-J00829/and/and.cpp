#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a2;
    cin>>n>>m;
    int a[1005]={};
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    for(int i=1;i<n-1;i++){
        a2=a[i]&&a[i+1];
        if((a[i-1]&&a[i])>a2)a2=a[i-1]&&a[i];
    }
    cout<<a2;
    return 0;
}
