#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);cin.tie(0);
    int n,m;
    cin >>n >> m;
    for(int i =1;i <= n;i++){
        cin >>a[i];
    }
    long long maxn;
    for(int i =1;i <= n;i++){
        for(j =i;j <= n;j++){
            maxn = max(a[i] & a[j],maxn);
        }
    }
}