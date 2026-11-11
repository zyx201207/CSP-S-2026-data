#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5,C=1e5;
int n,m,ans=1;
int a[N+5],cnt[N+5];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(abs(a[n])>1e5){
		if(a[1]==a[n]){
			ans=n;
		}else{
		for(int i=n-1;i>=1;i--){
				if(m>=a[n]-a[i]){
					m-=a[n]-a[i];
					ans++;
				}else break;
			}
		}
	}else{
		for(int i=1;i<=n;i++) cnt[a[i]+C]++;
		int nn=(unique(a+1,a+n+1)-(a+1)),s,ans1,m1;
		for(int i=nn;i>=1;i--){
			if(ans>=i) break ;
			ans1=cnt[a[i]+C],m1=m;
			for(int j=i-1;j>=1;j--){
				s=a[i]-a[j];
				if(m1>=s*cnt[a[j]+C]) m1-=s,ans1+=cnt[a[j]+C];
				else{
					ans1+=m1/s;
					break;
				}
//				cout<<m1<<' ';
			}
			ans=max(ans,ans1);
//			cout<<'\n';
		}
	}
	cout<<ans;
	return ;
}
signed main(){
	int T=1;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	cin>>T;
	while(T--) solve();
	return 0;	
}
//CCF保我有80分 
//I love CCF

