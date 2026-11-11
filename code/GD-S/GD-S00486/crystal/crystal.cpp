#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;
int n;
int a[500005];
int m;
signed main(){
	fastio;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool fA=1,fB=1;
	int d=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			if(a[i]!=a[i-1]) fA=0;
		}
		if(i>2){
			if(a[i]-a[i-1]!=d){
				fB=0;
			}
		}else if(i==2){
			d=a[i]-a[i-1];
		}
	}
	sort(a+1,a+n+1);
	if(fA){
		cout<<n;
		return 0;
	}
	if(fB){
		if(n*(n+1)*d <= 2*m){
			cout<<n;
			return 0;
		}
		int k=2*m/d;
		for(int i=(int)sqrt(k);i>=0;i--){
			if(i*(i+1)*d <= 2*m){
				cout<<min(n,i+1);
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		int sm=m,sum=1;
		for(int j=i-1;j>0;j--){
			if(a[i]-a[j] > sm) break;
			sm -= (a[i]-a[j]);
			sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
