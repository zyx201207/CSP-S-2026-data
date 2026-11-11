#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
	}else{
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
	}	
	cout<<ans;
}
