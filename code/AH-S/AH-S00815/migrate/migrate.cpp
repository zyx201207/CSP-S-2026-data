#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000005],ans;
struct node{
    ll f,cnt,sizee;
}a[2000005];
void dfs(ll l,ll r,ll sum,ll xb,ll cd){
    if(l==r){
        if(sum<a[xb].f){
            a[xb].f=sum;
            a[xb].sizee=cd;
            a[xb].cnt=1;
        }else if(sum==a[xb].f){
            if(cd<a[xb].sizee){
                a[xb].sizee=cd;
                a[xb].cnt=1;
            }else{
                a[xb].cnt++;
            }
        }
        return;
    }
    for(int i=l+1;i<=r;i++){
        if(x[i]-x[l]>d){
            return ;
        }
        dfs(i,r,sum+x[i]-x[l],xb,cd+1);
    }
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
        memset(x,0,sizeof(x));
        memset(a,0,sizeof(a));
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        ll mj=0;ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                a[mj+1].f=1e18;
                a[mj+1].sizee=1e18;
                dfs(i,j,0,++mj,2);
            }
        }
        for(int i=1;i<=mj;i++){
            if(a[i].cnt==2){
                ans++;
            }
        }
        cout<<ans<<'\n';
	}
	return 0;
}
