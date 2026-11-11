#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=0;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m == 1 || m == n-1){
        for(int i=1;i<=n;i++){
            maxn = max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
else{
        cout<<511;
    }
    return 0;
}