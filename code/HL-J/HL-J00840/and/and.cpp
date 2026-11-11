#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
typedef long long ll;
ll ans,n,a[N],sum,m,cnt[32],js;
bool k[N][32],j[32],zt;
vector<ll> s[32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		ll j=0;
		while(a[i]){
			k[i][++j]=a[i]%2;
			if(a[i]%2) cnt[j]++;
			a[i]/=2;
		}
	}
	for(int i=31;i>=1;i--){
		ans*=2;
		if(cnt[i]<m) continue;
		else if(!zt){
			ans=1;
			for(int j=1;j<=n;j++){
				if(k[j][i]){
					s[js].push_back(j);
				}
			}
			zt=1;js++;
		}
		else{
			ll mm=0;
			for(int j=0;j<s[js-1].size();j++){
				ll z=s[js-1][j];
				if(k[z][i]){
					mm++;
					s[js].push_back(z);
				}
			}
			if(mm>=m) ans++;
			else{
				s[js].clear();
				for(int j=0;j<s[js-1].size();j++){
				    ll z=s[js-1][j];
					s[js].push_back(z);
			    }
			}
			js++;
		}	
	}
	cout<<ans;
	return 0;
}