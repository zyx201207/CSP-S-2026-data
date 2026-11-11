#include <bits/stdc++.h>
using namespace std;
long long n,m,mx,a[200010],ans;
void dfs(int pre,int x,long long lst){
	if(pre==n){
		if(x==m){
			ans=max(lst,ans);
			return;
		}else{
			return;
		}
	}
	for(int i=pre+1;i<=n;i++){
		dfs(i,x+1,lst&a[i]);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout << mx;
	}else if(m==2){
		long long ans1;
		ans1=a[1]&a[2];
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans1=max(ans1,a[i]&a[j]);
			}
		}
		cout << ans1;
	}else if(m==n){
		long long ans1;
		ans1=a[1];
		for(int i=2;i<=n;i++){
			ans1&=a[i];
		}
		cout << ans1;
	}else{
		for(int i=1;i<=n;i++){
			dfs(i,1,a[i]);
		}
		cout << ans;
	}
	return 0;
}
