#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int n,m,d;
ll ans,a[N],s[N],e[N];
void dfs(int x,int l,ll sum){
	if(x==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=l+1;i<=n-(m-x)+1;i++){
		dfs(x+1,i,sum&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
	}else if(m==n){
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
	}else if(m==n-1){
		s[1]=a[1];
		for(int i=2;i<=n;i++){
			s[i]=s[i-1]&a[i];
		}
		e[n]=a[n];
		for(int i=n-1;i>=1;i--){
			e[i]=e[i+1]&a[i];
		}
		for(int i=1;i<=n;i++){
			if(i==1){
				ans=max(ans,e[i+1]);
			}else if(i==n){
				ans=max(ans,s[i-1]);
			}else{
				ans=max(ans,s[i-1]&e[i+1]);
			}
		}
	}else if(n<=20){
		for(int i=1;i<=n-m+1;i++){
			dfs(1,i,a[i]);
		}
	}else{
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
