#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,m,t;
ll a[500005],pre[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	bool special_A=1,special_B=1;
	ll cha=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!(special_A&&a[i]==i)) special_A=0;
		if(i==1) continue;
		if(i==2) cha=a[i]-a[i-1];
		if(!(special_B&&cha==a[i]-a[i-1])) special_B=0;
	}
	if(special_A){
		for(int i=1;i<=n;i++){
			if(ans+i>m){
				cout<<ans;
				return 0;
			}
			ans+=i;
		}
		cout<<ans;
		return 0;
	}
	if(special_B){
		cout<<m/cha;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		for(int j=0;j<=i;j++){
			ans=max(ans,(a[i]*(i-j+1)-(pre[i]-pre[j])<=m?i-j+1:ans));
		}
	}
	cout<<ans;
	return 0;
}

