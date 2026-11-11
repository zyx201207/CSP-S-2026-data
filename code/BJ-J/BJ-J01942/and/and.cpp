#include<bits/stdc++.h>
using namespace std;
int A[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int ans=0,n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A,A+n);ans=A[n-1];
    cout<<ans;
}
