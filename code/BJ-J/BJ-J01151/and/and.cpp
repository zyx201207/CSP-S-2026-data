#include<bits/stdc++.h>
using namespace std;
int a[200005];
int maxn[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d ",&a[i]);

    }
    sort(a,a+n+1);
    cout<<a[n-m+1];

    return 0;

}
