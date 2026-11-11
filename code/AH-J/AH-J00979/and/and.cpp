#include<bits/stdc++.h>
using namespace std;
long long a[100005],k=-1;
void h(long long x,long long y){
    k=max(k,x&y);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        for(int l=i+1;l<=n;l++){
            h(a[i],a[l]);
        }
    }



    cout<<k;

    return 0;
}
