#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[1000100],flag[1000010];
ll ner[500010],mer[500010],jieguo[500010];
ll maxn=-10000;
ll huo(ll n , ll m){
	ll lenn=0,lenm=0,sum=0;
	while(n){
		ner[++lenn]=n%2;
		n/=2;
		}
	while(m){
		mer[++lenm]=m%2;
		m/=2;
		}
	for(ll i=1;i<=min(lenm,lenn);i++){
		if(ner[i]==mer[i]&&ner[i]==1)sum+=pow(2,i-1);
		}
		return sum;
}
void dfs(ll n,ll m,ll shuliang,ll zhi,ll last){
	if(shuliang==m){
		maxn=max(maxn,zhi);
		return ;
	}
	if(last==n){
		return ;
	}
	for(ll i=last+1;i<=n;i++){
		if(flag[i]==0){
			ll nowzhi;
			if(shuliang==0)nowzhi=arr[i];
			else nowzhi=huo(zhi,arr[i]);
			flag[i]=1;
			shuliang++;
			dfs(n,m,shuliang,nowzhi,i);
			flag[i]=0;
			shuliang--;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
	}
	dfs(n,m,0,0,0);
	cout<<maxn;
	return 0;
}
