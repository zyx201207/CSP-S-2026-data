#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
ll n,d;
ll a[N];
ll a_num[N],a_step[N];
ll y[N];bool f[N];
void dfs(ll i,ll step){
	//if(i==5&&step==2) cout<<1; 
	if(a_step[i]<step&&a_step[i]!=0) return;//¼ôÖ¦ 
	if(step==a_step[i]){
		a_num[i]++;
	}
	if(step<a_step[i]){
		a_step[i]=step;
		a_num[i]=1;
	}
	for(ll j=y[i];j>=i+1;j--){
		if(a[j]-a[i]<=d){
			if(f[i]) y[i]=j,f[i]=0;
			dfs(j,step+1);
		}
	}	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i],y[i]=n,f[i]=1;
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			memset(a_num,0,sizeof(a_num));
			memset(a_step,0x3f,sizeof(a_step));
			dfs(i,0);
			for(ll j=1;j<=n;j++) if(a_num[j]==2) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
