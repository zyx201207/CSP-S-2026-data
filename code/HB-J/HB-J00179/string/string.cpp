#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    for(long long i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        //cout << a[i] << ' ' << c[i];
    }
    long long i = 1;
    long long j = n;
    long long ans = 0;
    while(i < j){
        long long p = min(a[i],a[j]);
        if(c[i] != c[j]){
            ans += p;
            //printf("c[%d] != c[%d],ans += %d\n",i,j,p);
        }
        a[i] -= p;
        a[j] -= p;
        //printf("now,a[%d] = %d,a[%d] = %d\n",i,a[i],j,a[j]);
        if(a[i] == 0) i++;
        if(a[j] == 0) j--;
    }
    cout << ans;
    return 0;
}
