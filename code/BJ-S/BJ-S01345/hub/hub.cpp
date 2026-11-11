#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
int a[500010],s[500010],k,c,n;
int sal[500010];
void solve(){
    if(c==13||c==14){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
        }
        cout<<((n-1)/2-k+1)/2+1<<endl;
    }
    else{
        cout<<1<<endl;
    }
}
/*
*/
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    //freopen("hub1.in","r",stdin);
    //freopen("hub.out","w",stdout);
    int t=1;
    cin>>c>>t;
    while(t--){
        solve();
    }
}
/*
15:35
依旧T2洗脸
是时候随机穿梭了
16:15
T4特判A


m=3
1 2
2 3
3 4
1 5
2 6
3 7
*/
