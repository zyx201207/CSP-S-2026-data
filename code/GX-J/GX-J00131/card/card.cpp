#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long ans[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout)
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            int t[n+5];
            t[a[j]]++;
            if(t[a[j]>1){
                for(int k=1;k<=j;k++){
                    ans[k]--;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
