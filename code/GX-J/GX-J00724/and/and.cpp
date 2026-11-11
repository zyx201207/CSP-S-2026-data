#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    long long a[210000];
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long ans[210000]={0};
    for(int i=1;i<=n;i++){
        for(int j=m;j>1;j--){
            ans[j]=max(ans[j],ans[j-1]&a[i]);
        }
        ans[1]=max(ans[1],a[i]);
    }
    cout<<ans[m];
    return 0;
}
