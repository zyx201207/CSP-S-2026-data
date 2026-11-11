#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=(a); i<=(b); i++)
#define IloveCCF ios::sync_with_stdio(0);
#define Pleasegivememorepts cin.tie(0);
#define Thankyou cout.tie(0);
typedef long long ll;
const int N=5e5+5;
int n, m;
ll a[N];
ll b[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    IloveCCF
    Pleasegivememorepts
    Thankyou
    cin >> n >> m;
    b[0]=0;
    rep(i, 1, n)
        cin >> a[i];
    sort(a+1, a+n+1);
    rep(i, 1, n)
    	b[i]=b[i-1]+a[i];
    int i=1, j=1;
    int ans=-1;
    while (i<=n && j<=n) {
        ll k=a[j]*(j-i+1);
        ll h=b[j]-b[i-1];
//        cout << k << " " << h << '\n';
        if (k-h<=m) ans=max(ans, j-i+1), j++;
        else i++;
    }
    cout << ans;
    return 0;
}