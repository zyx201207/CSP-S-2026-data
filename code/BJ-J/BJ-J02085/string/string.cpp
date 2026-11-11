#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n; ll len, ans;
struct Paragraph{
    ll x; char c;
}a[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i].x >> a[i].c;
        len += a[i].x;
    }

    ll L = 0, R = 0, dL = 0, dR = 0;
    int iL = 0, iR = n+1;
    char cL, cR;

    while(iL < iR){
        if(L == R){
            L += a[++iL].x;
            dL += a[iL].x;
            cL = a[iL].c;
            continue;
        }

        if(L < R){
            L += a[++iL].x;
            dL += a[iL].x;
            cL = a[iL].c;
        }

        else if(L > R){
            R += a[--iR].x;
            dR += a[iR].x;
            cR = a[iR].c;
        }

        ll d = min(dL, dR);
        dL -= d, dR -= d;
        if(cL != cR) ans += d;
    }

    cout << ans;

    return 0;
}
