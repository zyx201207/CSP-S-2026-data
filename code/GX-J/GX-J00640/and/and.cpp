#include<bits/stdc++.h>
using namespace std;
long long m,n,x[100006];
long long ans[100006];
bool cmp(int q,int p){
    return q>p;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        cin >> x[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ans[j]=x[i]&x[j];
        }
    }
    sort(ans+1,ans+1+m,cmp);
    cout << ans[1];
    return 0;
}
