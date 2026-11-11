#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,x,y,p[100000];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--){
        memset(p,0,sizeof p);
        ll n,k,maxn=-1;
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            cin >>x >> y;
            p[y-x]++;
        }
        for(int i=1;i<=n;i++){
            if(p[i]>maxn){
                maxn=p[i];
            }
        }
        cout << maxn << endl;
    }
    return 0;
}
