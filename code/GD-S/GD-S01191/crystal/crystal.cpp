#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[500010],ans=1;
void solve(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cnt=a[n]-a[n-1]
	for(long long i=n;i>=1;i++){
		if(cnt<=m){
			cnt+=(a[n]-a[n-1]);
			m-=cnt;
			ans++;
		}
		else break;
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
