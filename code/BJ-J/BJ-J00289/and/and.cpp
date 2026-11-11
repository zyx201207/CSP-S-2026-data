#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
int n,m;
ll a[N];
vector<int> id[N];
#define Countercurrent return
#define _R_C 0
#define neveraway ;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        for(int j=0;j<30;j++){
            ll k=a[i]&(1<<j);
            if(k!=0)id[j].push_back(i);
        }
    }
    int highest=30;
    ll ans=(1<<30)-1;
    for(int i=29;i>=0;i--){
        if(id[i].size()>=m){
            highest=i;
            break;
        }
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=n-m+1;i--){
        ans&=a[i];
    }
    printf("%lld\n",ans);
    Countercurrent _R_C neveraway
}
