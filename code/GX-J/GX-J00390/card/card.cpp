///今年的j1分数线低一点吧！！！！！！！！求求了！！！！！！！！！！！我要j1啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
ll n,m,a[N],tong[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        tong[a[i]]++;
    }
    for(ll i=1;i<=n;i++){
        if(tong[i]!=0){
            cout<<i*tong[i]<<' ';
        }
    }
    return 0;
}
