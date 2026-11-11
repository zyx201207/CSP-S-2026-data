#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6;
int a[N];
char c[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> a[i] >> c[i];
    }
    ll pre = 1, nxt = n;
    ll sum = 0;
    while(pre<nxt){
        ll x;
        if(a[pre]>a[nxt]){
            x = a[nxt];
            if(c[pre]!=c[nxt]){
                sum+=x;
            }
            a[pre]-=a[nxt];
            nxt--;
        }else if(a[pre]<a[nxt]){
            x = a[pre];
            if(c[pre]!=c[nxt]){
                sum+=x;
            }
            a[nxt]-=a[pre];
            pre++;
        }else{
            x = a[pre];
            if(c[pre]!=c[nxt]){
                sum+=x;
            }
            a[nxt] = a[pre] = 0;
            pre++;
            nxt--;
        }
    }
    cout << sum;
    return 0;
}
