#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,maxn;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;

    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i =1;i<=n;i++){
            maxn =max(maxn,a[i]);
        }
    }

    if(m==2){
        for(int i =1;i<=n;i++){
            for(int j=1;j<=n;j++){
                maxn = max(maxn,a[i]&a[j]);
            }
        }
    }
    cout<<maxn;
    return 0;
}
