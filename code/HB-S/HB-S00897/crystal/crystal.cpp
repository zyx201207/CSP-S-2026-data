#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
ll n,m,cnt = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<int>v(N),dis(N);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll mid = v[n/2];
    for(int i =1;i<=n;i++){
        dis[i] = abs(v[i]-mid);
    }
    sort(dis.begin(),dis.end());
    for(int i=1;i<=n;i++){
        if(m-dis[i]>=0){
            cnt++;
            m-=dis[i];
        }
        else break;
    }
    cout<<cnt;
    return 0;
}
