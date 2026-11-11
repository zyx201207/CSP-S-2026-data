#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i = a;i <= b;i++)
using namespace std;
int n,m;
int a[500005],ans[300005],dq[500005];

int main(){
    //Miku is the best!
    //39!
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    rep(i,1,n){
        cin >> a[i];
    }
    rep(i,1,n){

        int f = 1;
        rep(j,i,n){
            dq[f++] = a[j];
            rep(k,1,f-1){
                if(dq[k] == dq[f-1]){
                    rep(l,k,f-2){
                        dq[l] = 0;
                    }
                }
            }
        }
        rep(j,1,f-1){
            if(dq[j] != 0) ans[dq[j]]++;
        }
    }
    rep(i,1,m){
        cout << ans[i] << ' ';
    }
    return 0;
}
