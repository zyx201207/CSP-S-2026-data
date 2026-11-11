#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+10;
int a[N];
int num[N][30];
int n,m;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;++i){
		int temp=a[i],j=29;
		while(temp){
			num[i][j]=num[i-1][j];
			if(temp&1) num[i][j]++;
			--j,temp>>=1;
		}
		while(j>=0) num[i][j]=num[i-1][j],--j;
	}
	int ans=0;
//	int j=0;
//	while(num[n][j]<m and j<30) ++j;
//	if(j==30){
//		cout<<0;
//		return;
//	}
	int st=1,ed=n;
	for(int k=0;k<30;++k){
		if(num[ed][k]<m) continue;
		while(num[st][k]==num[st+1][k] and st<ed) ++st;
		while(num[ed][k]==num[ed-1][k] and st<ed) --ed;
		ans+=(1<<(30-k-1));
	}
	cout<<ans;
//	int ans=a[1];
//	for(int i=2;i<=m;++i) ans&=a[i];
//	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
}
