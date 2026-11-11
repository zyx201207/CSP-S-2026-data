#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        long long maxn;
        for(int i=2;i<=n;i++){
            maxn=max(a[i],a[i-1]);
        }
        cout<<maxn;
        return 0;
    }

    return 0;
}


