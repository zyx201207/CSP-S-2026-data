#include<bits/stdc++.h>

using namespace std;
#define int long long
int n,m;
const int N = 2e5+10;
int a[N],ans[N]; 
int mmaxx = 0;
void dfs(int step,int xuan){
	if(step>n){
		if(xuan==m){
			int tmp = ans[1];
			for(int i = 2;i<=m;i++){
				tmp &= ans[i];
			}
			mmaxx = max(mmaxx,tmp);
		}
		return;
	}
	dfs(step+1,xuan);
	ans[xuan+1] = a[step];
	dfs(step+1,xuan+1);
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mmax = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		mmax = max(mmax,a[i]);
	}
	if(n<=20){
		dfs(1,0);
		cout<<mmaxx<<"\n";
	}
	else if(m==1){
		int maxn = 0;
		for(int i = 1;i<=n;i++){
			maxn = max(maxn,a[i]);
		}
		cout<<maxn<<"\n";
	}
	else if(m==n){
		int ans = a[1];
		for(int i = 2;i<=n;i++){
			ans &= a[i];
		}
		cout<<ans<<"\n"; 
	}
	else if(m==2){
		int ans = 0;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				ans = max(ans,a[i]&a[j]); 
			}
		}
		cout<<ans<<"\n";
	}
	else if(mmax<4){
		int cnt0 = 0,cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i = 1;i<=n;i++){
			if(a[i]==0) cnt0++;
			else if(a[i]==1) cnt1++;
			else if(a[i]==2) cnt2++;
			else if(a[i]==3) cnt3++;
		}
		if(cnt3>=m) cout<<3<<"\n";
		else if(cnt3+cnt2>=m) cout<<2<<"\n";
		else if(cnt3+cnt1>=m) cout<<1<<"\n";
		else cout<<0<<"\n";
	}
	else cout<<0<<"\n";
	return 0;
}
