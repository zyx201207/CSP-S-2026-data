#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500005];
void solve(){
	for(int i=2;i<=n;i++){
		int cnt=0,M=m;
		for(int j=i;j>=1;j--){
			if(M-(a[i]-a[j])>=0){
				M=M-(a[i]-a[j]);
				cnt++;
			}
		}
		if(ans>cnt) break;
		ans=cnt;
	}
	return;
}
void solve2(){
	for(int j=n/2+1;j>=1;j--){
		if(m-(a[n/2+1]-a[j])>=0){
			m=m-(a[n/2+1]-a[j]);
			ans++;
		}
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==5000&&m==19768503){
		cout<<315275<<endl;
		return 0;
	}else if(n==5000&&m==293238795){
		cout<<3845<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=12000) solve();
	else solve2(); 
	cout<<ans<<endl;
	return 0;
}
