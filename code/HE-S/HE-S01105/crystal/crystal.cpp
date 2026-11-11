#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[500010];
ll diff[10010][10010],cnt[50010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	ll d = a[2]-a[1];
	bool flag = 1;
	for(int i=2;i<=n;i++) if(a[i]-a[i-1]!=d) flag=0;
	if(flag){//特殊性质AB
		ll i = 1;
		while(m >= (long long)(1+i)*i/2*d) i++;
		cout<<i<<'\n';	
	}else{
		int num = 1;
		int lastnum = 0;
		for(int i=1;i<=n;){//初始化cnt 
		  	if(num!=1) lastnum += num;
			num = 1;
			int pos = i;
			while(i<n && a[i]==a[i+1]) num++,i++; 
			if(lastnum!=0) cnt[pos-lastnum+1] += num;
			else cnt[pos] += num;
			i++;
		}
		n = unique(a+1,a+1+n)-a-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				diff[i][j] = a[j]-a[i];
			}
		}

		for(int j=2;j<=n-1;j++){
			vector<ll> cur;
			for(int i=1;i<=j-1;i++) cur.push_back(diff[i][j]);
			sort(cur.begin(),cur.end());
			ll tem = 0,k = 0;
			for(auto &x:cur){
				tem+=x;
				if(tem>m){
					break;
				}
				k++;
			}
			cnt[j] += k;
		}
		
		ll ans = 0;
		for(int i=1;i<=n;i++) ans = max(ans,cnt[i]);
		cout<<ans<<'\n';
	}
	return 0;
} 
