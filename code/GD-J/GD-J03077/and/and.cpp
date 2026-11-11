#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 1000005
int a[maxn];
int c[maxn];
bool vis[maxn];
int ans=0;
int n,m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n<=2000){
		if(m==1){
			int mx=0;
			for(int i = 1;i <= n;i++)mx=max(mx,a[i]);
			cout << mx << '\n';
		}else if(m==n){
			int mx=(1LL<<32)-1;
			for(int i = 1;i <= n;i++)mx=mx&a[i];
			cout << mx << '\n';
		}else if(m==2){
			int mx=0;
			for(int i = 1;i <= n;i++){
				for(int j = 1;j < i;j++){
					mx=max(mx,a[i]&a[j]);
				}
			}
			cout << mx << '\n';
		}
		return 0;
	}else if(m==n-1){
		int mx=0;
		c[n+1]=(1LL<<32)-1;
		for(int i = n;i>=1;i--){
			c[i]=c[i+1]&a[i];
		}
		int st=(1LL<<32)-1; 
		for(int i = 1;i < n;i++){
			mx=max(mx,st&c[i+1]);
			st=st&a[i];
		}
		cout << mx << '\n';
	}else{
		for(int i = 31;i>=0;i--){
			int cnt=0;
			for(int j = 1;j <= n;j++){
	//			cout << (a[j]>>i) << "\n";
				if(((a[j]>>i)&1LL)&&(!vis[j])){
					cnt++;
				}
			}
	//		cout << cnt << '\n';
			if(cnt>=m){
				ans+=(1LL<<i);
				for(int j = 1;j <= n;j++){
					if((a[j]>>i)==0)vis[j]=true;
				}
			}
			cnt=0;
			for(int j = 1;j <= n;j++)cnt+=(!vis[j]);
			if(cnt<m)break;
	//		cout << '\n';
		}
		cout << ans << '\n';
	}
	
	return 0;
} 
