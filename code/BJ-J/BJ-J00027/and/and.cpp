#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll getll(){
    int f = 1;
    ll sum = 0;
    int c = getchar();

    while(c > '9' || c < '0'){
        if(c == '-'){
            f = -1;
        }
        c = getchar();
    }

    while(c >= '0' && c <= '9'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }

    if(c != EOF){
        ungetc(c,stdin);
    }

    return sum*f;
}

ll a[200005];
ll b[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n = getll();
    ll m = getll();
    ll mx = 0;
    ll ans = 0;

    for(int i=0;i<n;i++){
        a[i] = getll();
        mx = max(a[i],mx);
    }


    int p = 1;
    while(p<=mx){
        p *= 2;
    }
    p /= 2;


    for(ll i=p;i;i>>=1){
        ll nn=0;
        for(ll j=0;j<n;j++){
            if(a[j] & i){
                nn++;
                b[nn-1] = a[j];
            }
        }
        if(nn >= m){
            n = nn;
            ans += i;
            for(ll j=0;j<nn;j++){
                a[j] = b[j];
            }
        }
    }
    printf("%lld", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

