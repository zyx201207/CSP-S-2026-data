#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    ll n,ans=0,ts=1;
    cin >> n;
    char w[n+1],xw[1000000];
   // int sizee[n+1];
    for(ll i=1;i<=n;i++){
     //   cout << i;
        ll x;
        char cha;
        cin >> x >> cha;
        /*w[i]=cha;
        sizee[i]=x;*/
        for(ll j=1;j<=x;j++,ts++){

            xw[ts]=cha;
        }
    }
    ts--;
    if(ts%2!=0){
        for(ll i=ts/2+2,j=ts/2;i<=ts;i++,j--){
           // cout << i<<j;
            if(xw[i]!=xw[j]){
                ans++;
             //   cout<< i<<' '<<j<<endl<<xw[i]<<"and"<<xw[j]<<endl;
            }
        }
    }
    if(ts%2==0){
        for(ll i=ts/2+1,j=ts/2;i<=ts;i++,j--){
          //  cout << i<<j;
            if(xw[i]!=xw[j]){
                ans++;
              //  cout<< i<<' '<<j<<endl<<xw[i]<<"and"<<xw[j]<<endl;
            }
        }
    }
    cout << ans;
    return 0;
}
