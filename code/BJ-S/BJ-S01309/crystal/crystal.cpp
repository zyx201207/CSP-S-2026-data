#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=5e5+5;
ll n, m, a[MAXN], maxa=0;
ll ca(ll mid){
    ll fm=m, c=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]>mid)continue;
        if(fm>=mid-a[i]){fm-=mid-a[i],c++;
        //cout << mid<< " 123 "<<a[i] <<'\n';
        }
        else break;
    }return c;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll maxb=-1e13, minb=1e13;
    scanf("%lld %lld", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%lld", &a[i]);
        maxb=max(maxb, a[i]);
        minb=min(minb, a[i]);
    }
    sort(a, a+n);
    //cout << maxb<< " " << minb << '\n';
    //for(int i=0;i<n;i++)cout << a[i] << ' ';
    //cout << endl;
    for(ll i=minb;i<=maxb;i++){
        ll ret=ca(i);
        //printf("%lld %lld\n", i, ret);
        maxa=max(maxa, ret);
    }printf("%lld\n", maxa);
    fclose(stdin);
    fclose(stdout);
    return 0;
}