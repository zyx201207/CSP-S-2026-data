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

struct data{
    ll c;
    ll n;
};

data l[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n = getll();
    ll sum = 0;
    for(ll i=0;i<n;i++){
        ll a = getll();
        getchar();
        char b = getchar();
        l[i] = {a,b};
        sum += a;
    }
    sum /= 2;

    ll t1 = 0;
    ll w1 = -1;
    ll t2 = 0;
    ll w2 = n;
    ll ans = 0;

    while(w1 +1 != w2 && w1 != w2){
        if(t1 == 0){
            w1++;
            t1 += l[w1].c;
        }
        if(t2 == 0){
            w2--;
            t2 += l[w2].c;
        }
        if(t1>=t2){
            t1 -= t2;
            if(l[w1].n != l[w2].n) ans += t2;
            t2 = 0;
        }
        else {
            t2 -= t1;
            if(l[w1].n != l[w2].n) ans += t1;
            t1 = 0;
        }
    }
    printf("%lld", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
