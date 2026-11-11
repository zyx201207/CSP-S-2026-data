#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[1000010];
ll sta[1000010];
ll ls;
bool s[1000010];
ll ans[1000010];
void spush(ll an,ll ls){
	ls++;
	sta[ls]=an;
	s[an]=1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	else if(m==n){
		while(m--) cout<<n<<" ";
		return 0;
	}
	else{
		for(ll i=1;i<=n;i++){
			ls=0;
			for(ll j=1;j<=m;j++) s[j]=0;
			for(ll j=i;j<=n;j++){
				if(s[a[j]]){
					for(;ls>=1;ls--){
						if(sta[ls]==a[j]){
							break;
						}
						else s[sta[ls]]=0;
					}
				}else spush(a[j],ls);
			}for(ll j=1;j<=m;j++) ans[j]+=s[j];
		}for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}
