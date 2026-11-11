#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int a[N+5],qzh[N+5];
char b[N+5];
int n;
#define int long long

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int c=1,d=n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
        qzh[i]=qzh[i-1]+a[i];
    }
    int sum = 0;
    while(c<=d){
        if(b[c]!=b[d]){
            sum+=min(a[c],a[d]);
        }
        if(a[c]==a[d]){
            c++;
            d--;
        }else if(a[c] < a[d]){
            a[d]-=a[c];
            c++;
        }else if(a[c] > a[d]){
            a[c]-=a[d];
            d--;
        }
    }
    cout << sum;

    return 0;
}
