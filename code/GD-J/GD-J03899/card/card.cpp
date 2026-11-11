#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+9;
ll a[N],s[N],ans[N];
ll n,m,idx,pre;
bool check(ll x){
	for(int i=idx;i>0;i--){
		if(s[i]==x){
			pre=i;
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		memset(s,0,sizeof(s));
		idx=0;
		for(int j=i;j<=n;j++){
			if(check(a[j])){
				for(int x=pre;x<=idx;x++){
					s[x]=0;
				}
				idx=pre-1;
			}
			s[++idx]=a[j];
		}
		for(int j=1;j<=idx;j++){
			ans[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i]<<" ";
	}
	return 0;
} 
