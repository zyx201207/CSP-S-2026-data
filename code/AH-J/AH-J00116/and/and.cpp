#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int ans;
void dfs(int idx,int sum,int choose) {
	if(choose>m) return ;
	if(idx==n+1) {
		if(choose==m) {
			ans=max(ans,sum);
		}
		return ;
	}
	dfs(idx+1,sum&a[idx],choose+1);
	dfs(idx+1,sum,choose);
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int MAXN=1;
	int maxn=-1;
	for(int i=1; i<=30; i++) {
		MAXN*=2;
	}
	MAXN--;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=20) {
		dfs(1,MAXN,0);
		cout<<ans;
	} else if(n<=2000) {
		if(m==1) {
			cout<<maxn;
		} else if(m==n) {
			int flag=a[1];
			for(int i=2; i<=n; i++) {
				flag=flag&a[i];
			}
			cout<<flag;
		} else {
			dfs(1,MAXN,0);
			cout<<ans;
		}
	} else {
		if(maxn<4) {
			int cnt1=0,cnto=0,cnt3=0;
			for(int i=1; i<=n; i++) {
				if(a[i]%2==0) {
					cnto++;
				}
				if(a[i]==1) {
					cnt1++;
				} else {
					cnt3++;
				}
			}
			if(m<=cnt1+cnt3) {
				if(cnt1) {
					cout<<1;
				} else {
					cout<<3;
				}
			} else {
				cout<<0;
			}
		}else{
			sort(a+1,a+n+1);
			int num=a[n];
			for(int i=n-1;i>=n-m+1;i--){
				num=num&a[i];
			} 
			cout<<num;
		}
	}
	return 0;
}

