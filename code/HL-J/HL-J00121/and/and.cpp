#include<bits/stdc++.h>
using namespace std;
int m,n,a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<a[1];
    }else{
        cout<<0;
    }
    return 0;
}
