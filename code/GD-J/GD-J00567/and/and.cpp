#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[300000],mx,t,cnt;
void dfs(int now){
	if(now==n){
		if(cnt==m){
			mx=max(t,mx);
		}
		if(cnt+1==m){
			mx=max(t^a[n],mx);
		}
	}
	dfs(now+1);
	t=t^a[now];
	cnt++;
	dfs(now+1);
	t=t^a[now];
	cnt--;
	return;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1);
		cout<<mx;
	}else{
		if(m==1){
			for(int i=1;i<=n;i++){
				mx=max(mx,a[i]);
			}
			cout<<mx;
			return 0;
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					mx=max(mx,a[i]^a[j]);
				}
			}
			cout<<mx;
			return 0;
		}else if(m==n){
			for(int i=1;i<=n;i++){
				mx=mx^a[i];
			}
			cout<<mx;
			return 0;
		}else if(m==n-1){
			for(int i=1;i<=n;i++){
				mx=mx^a[i];
			}
			for(int i=1;i<=n;i++){
				mx=max(mx,mx^a[i]);
			}
			cout<<mx;
			return 0;
		}else{
			return 0;
		}
	}
	return 0;
}
