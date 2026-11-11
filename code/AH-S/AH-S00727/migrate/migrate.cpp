#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[2000010];
bool f=0;
map<ll,ll>t;
ll n,d;
void dfs(ll start,ll finish,ll cnt){
    if(start>finish) return;
    if(f) return;
    if(start==finish){
        t[cnt]++;
        return;
    }
    for(int i=start+1;i<=finish;i++){
        if(a[i]-a[start]<=d){
            dfs(i,finish,cnt+1);
        }
    }
    return;
}
void changef(){
    f=0;
    auto it=t.begin();
    if(it->second==2){
        f=1;
    }else{
        f=0;
    }
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ll c,T;
    cin>>c>>T;
    while(T--){
        t.clear();
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+3;j<n;j++){
                t.clear();
                f=0;
                dfs(i,j,0);
                changef();
                if(f){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
