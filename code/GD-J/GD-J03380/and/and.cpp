#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+7;
unordered_map<int,int> szh; 
int n,m,a[N],omo,ans,cnt0,cnt1,cnt2,cnt3;
bool vis[N],syh=1; 
int we[32];
void dfs(int pos,int k) {
	if(pos==m+1) {
		ans=max(ans,k);
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=1;
			dfs(pos+1,k&a[i]);
			vis[i]=0;
		} 
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]>=4) syh=0;
		if(a[i]==0) cnt0++;
		if(a[i]==1) cnt1++;
		if(a[i]==2) cnt2++;
		if(a[i]==3) cnt3++;
	}
	for(int i=0;i<=31;i++) omo+=(1<<i);
	if(syh) {
		if(cnt3>=m) cout<<3;
		else if(cnt3+cnt2>=m) cout<<2;
		else if(cnt3+cnt1>=m) cout<<1;
		else cout<<0;
	} 
	else if(m==n-1) {
		for(int i=1;i<=n;i++) {
			for(int j=31;j>=0;j--) {
				we[j]+=(a[i]>>(j-1))&1;
			}
		}
		for(int i=1;i<=n;i++) {
			int res=0;
			for(int j=31;j>=0;j--) {
				we[j]-=(a[i]>>(j-1))&1;
			}
			for(int j=31;j>=0;j--) {
				if(we[j]==m) res+=(1<<(j-1));
			}
			ans=max(ans,res);
			for(int j=31;j>=0;j--) {
				we[j]+=(a[i]>>(j-1))&1;
			}
		}
		cout<<ans;
	}
	else if(n<=2000) {
		dfs(1,omo);
		cout<<ans;
	}
	else{
		int p=1;
		for(int i=0;i<31;i++) {
			szh[p]=0;
			p*=2;
		}
		for(int i=1;i<=n;i++) {
			szh[a[i]]++;
		}
		p=1;
		for(int i=0;i<31;i++) {
			if(szh[p]>=m) ans=p;
			p*=2;
		}
		cout<<ans;
	}
}

