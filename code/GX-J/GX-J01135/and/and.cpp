#include <bits/stdc++.h>
using namespace std;

int a[1000000005];
int cnt[1000];
int n,m;
int main(){
    freopen("and .in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt[i] = a[i] and a[j];
        }
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]>=cnt[i+1]) maxn = cnt[i];
    }
    cout<< cnt[maxn];
    return 0;
}
