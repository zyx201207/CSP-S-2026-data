#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt,x,posl=1,posr,ans;
char k;
struct node{
    ll num;
    char c;
}a[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>x>>k;
        if (k==a[cnt].c) a[cnt].num+=x;
        else{
            a[++cnt].num=x;
            a[cnt].c=k;
        }
    }
    posr=cnt;
    while (posl<posr){
        ll skp=min(a[posl].num,a[posr].num);
        if (a[posl].c!=a[posr].c) ans+=skp;
        a[posl].num-=skp;
        a[posr].num-=skp;
        if (a[posl].num==0) posl++;
        if (a[posr].num==0) posr--;
    }
    cout<<ans;
    return 0;
}