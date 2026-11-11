#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int l,k,ans=0;
    cin>>l>>k;
    int n[l];
    for(int i=0;i<=l;i++){
        cin>>n[i];
    }
    sort(n,n+l);
    cout<<n[l/2];
}
