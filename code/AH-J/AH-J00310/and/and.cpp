#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,i,m,ans,cnt[50],S=0,Ans,j;
map<ll,ll> mp;
struct Node{
	ll a,f;
}x[N];
bool cmp(Node A,Node B){return A.a>B.a;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    if(n<=5000&&m==2){
		for(i=1;i<=n;i++) cin>>x[i].a;
        for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i!=j) Ans=max(Ans,(ll)(x[i].a&x[j].a));
			}
		}
		cout<<Ans;
		return 0;
	}
    for(i=1;i<=n;i++){
		cin>>x[i].a;
		mp[x[i].a]++;
		ll s=1;
		while(s<=x[i].a){
			x[i].f++;
			s*=2;
		}
		cnt[x[i].f]++;
	}
    sort(x+1,x+n+1,cmp);
    for(i=1;i<=n;i++){
		if(mp[x[i].a]>=m){
			Ans=max(Ans,x[i].a);
		}
	}
    for(i=1;i<=n;i++){
		if(cnt[x[i].f]<m) continue;
		if(ans==0) ans=x[i].a;
		else ans=(ans&x[i].a);
		S++;
		if(S==m) break;
	}
	cout<<max(Ans,ans);
	return 0;
}
