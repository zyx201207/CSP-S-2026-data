#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    if(m==1){
        cout<<a[n-1];
    }
    else{
        cout<<0;
    }
    return 0;
}
