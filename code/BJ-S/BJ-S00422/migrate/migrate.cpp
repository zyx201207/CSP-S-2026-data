#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        ll n,d;
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> x[i];
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=n;j>i+1;j--){
                ll cnt=x[j]-x[i];
                if(cnt>d){
                    ll cnnt=cnt-d;
                    if(cnnt<d){
                        ll cd=d/2;
                        if(d%2!=0){
                            cd++;
                        }
                        if(cd==1){
                            ans++;
                        }else if(cnt>cd&&cnt%cd!=0){
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
