#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N=(ll)2*(1<<30)-1;
ll n,m,sum=-10000007;
ll a[200005];
ll dp[200005];
bool vis[200005];
ll bao(ll ai,ll k,ll d){
	if(d>m)return ai;
	ll suma=-10000007;
	for(ll j=1;j<=n;j++){
		if(j==k)continue;
		suma=max(suma,bao(ai&a[j],j,d+1));
	}
	return suma;
}
void bao_2(){
	sum=-10000007;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue; 
			sum=max(sum,a[i]&a[j]);
		}
	}
	cout<<sum<<endl;
}
void dpt(){
	ll nm=m;
	for(int i=0;i<=m+1;i++)dp[i]=N;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(dp[j-1]==N){
				dp[j]=dp[j-1]&a[i];
				vis[i]=true;
				nm--;
			}
			else if(dp[j-1]&a[i]>=dp[j-1]){
				dp[j]=dp[j-1]&a[i];
				vis[i]=true;
				nm--;
			}else{
				dp[j]=dp[j-1];
				nm++;
			}
		}
	}
	while(nm>0){
		ll t=-10000007;
		ll k;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(dp[m]&a[i]>=t){
					t=dp[m]&a[i];
					k=i;
				}
			}
		}
		vis[k]=true;
		dp[m]=t;
		nm--;
	}
	cout<<dp[m]<<endl;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=20){
		for(int i=1;i<=n;i++){
			sum=max(sum,bao(a[i],i,2));
		}
		cout<<sum;
	}else if(m==1){
		cout<<a[n];
	}else if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}else if(m==2){
		bao_2();
	}else if(a[n]+1==2*(a[n-1]+1)){
		cout<<a[n-m+1];
	}else {
		dpt();
	}
	return 0;
}

