#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[100010];
ll cnt[500010];
ll last[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    memset(last,-1,sizeof last);
    for(int i=1;i<=n;i++)   scanf("%lld",&a[i]);
    if(m==2){
        ll c=1;
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]){
                c++;
            }
            else{
                if(a[i-1]!=a[n])    cnt[a[i-1]]+=c;
                c=1;
            }
        }
        cnt[a[n]]=n;
    }
    else{
        for(int i=n;i>=1;i--){
            if(last[a[i]]==-1)  last[a[i]]=i;
            for(int j=last[a[i]];j<=n;j++){
                cnt[a[j]]++;
                if(last[a[j]]!=-1)  j=last[a[j]];
            }
        }
    }
    for(int i=1;i<=m;i++)   printf("%lld ",cnt[i]);
    return 0;
}
