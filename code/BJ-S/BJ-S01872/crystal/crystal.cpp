#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],cnt;
int k;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int r=n,l=n; r>0&&l>1; --r){
        while(l>1&&cnt+a[r]-a[l-1]<=m)cnt+=a[r]-a[--l];
        k=max(k,r-l+1);
        cnt-=(r-l+1)*(a[r]-a[r-1]);
    }
    printf("%d",k);

    return 0;
}
