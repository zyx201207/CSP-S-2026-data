#include <bits/stdc++.h>
using namespace std;
int m,n,cnt;
long long cnt1;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(a[i]<a[i+1]){
                cnt = a[i+1];
                a[i+1] =a[i];
                a[i] = cnt;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cnt1=a[m];

    }
    cout << cnt1;
    return 0;
}
