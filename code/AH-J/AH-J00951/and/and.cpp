#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[400000],ans=-1;
void dfs(ll i,ll m,ll sum){
	if(i>n&&m==0){
		if(sum>ans){
			ans=sum;
		}
		return ;
	}
	if(sum<=ans){
		return ;
	}
	for(ll j=i;j<=n;j++){
		dfs(i+1,m-1,sum&a[i]);
		dfs(i+1,m,sum);
	}
}
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	if(pow(2,n)<=100000000){
		dfs(1,m,a[1]);
		cout<<ans;
		return 0;
	}
	ans=a[n];
	for(ll i=n;i>=1;i--){
		if(m==0){
			continue;
		}
		else{
			ans&=a[i];
			m--;
		}
	}
	cout<<ans;
	return 0;
}
