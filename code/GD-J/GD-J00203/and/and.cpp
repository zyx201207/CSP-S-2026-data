#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;

int n,m,ans;
int a[N];
void dfs(int dep,int s,int q) {
	if(dep>=m) {
		//cout<<s<<endl;
		ans=max(ans,s);
		return ;
	}
	if(q>n)return ;
	dfs(dep+1,s&a[q],q+1);
	dfs(dep,s,q+1);
	return ;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int ma=0;
	int fl=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>4)fl=0;
		ma=max(ma,a[i]);
	}
	if(m==1) {
		cout<<ma;
		return 0;
	}
	else if(m==2) {
		for(int i=1; i<n; i++) {
			for(int j=i+1; j<=n; j++) {
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n<=2000){
		for(int i=1;i<=n;i++)dfs(1,a[i],i+1);
		cout<<ans;
		return 0;
	}
	else if(fl){
		int cnt0=0,cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt0++;
			if(a[i]==1)cnt1++;
			if(a[i]==2)cnt2++;
			if(a[i]==2)cnt2++;
		}
		if(cnt3>=m)cout<<3;
		else if(cnt2+cnt3>=m)cout<<2;
		else if(cnt1+cnt3>=m)cout<<1;
		else cout<<0;
		return 0;
	}
	return 0;
}
