#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100000],a1[100000],m,maxn=-1,maxa=-1,cnt,ak;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    ll mk=m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    for(int i=1;i<=n;i++){
        a1[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(maxa<a1[i]){
            maxa=a1[i];
        }
    }
    for(int i=1;i<=n;i++){
        cnt=maxa;
        mk=m;
        ak=a[i];
        for(int i=1;i<=n;i++){
            if(ak<a[i]){
                continue;
            }else{
                mk-=ak-a[i];
                cnt++;
                if(mk<=0){
                    break;
                }
            }
        }
        if(maxn<cnt){
            maxn=cnt;
        }
    }
    cout << maxn;
    return 0;
}
