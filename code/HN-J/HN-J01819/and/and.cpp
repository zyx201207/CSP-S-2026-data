#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int const N = 2e5 + 5;
int a[N],c[50],l[N],r[N],n,m,ans;
bool cmp(int x,int y){
	return x>y;
}
int zjz(int k){
	int r=1,u=0,cnt=0;
	while(r<k){
		u++;
		int p=r&k;
		if(p==r) cnt+=u; 
	}
	return u; 
}
int dfs(int st,int l,int p){
	if(st>n){
		if(l==m) return p; 
		else return 0; 
	}
	if(l<m){
	 	return max( dfs(st+1,l+1,p&a[st]) , dfs(st+1,l,p) ); 
	}else{
		return dfs(st+1,l,p); 
	} 
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		ans = a[1]; 
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int p = a[i] & a[j];
				ans = max(ans,p); 
			}
		} 
	}else if(m==n-1){
		l[0] = r[n+1] = pow(2,31)-1; 
		for(int i=1;i<=n;i++){
			l[i] = l[i-1]&a[i]; 
		}
		for(int i=n;i>=1;i++){
			r[i] = r[i+1]&a[i];
		}
		for(int i=1;i<=n;i++){
			int p = l[i-1] & r[i+1];
			ans = max(p,ans); 
		} 
	}else if(m==n){
		int p = pow(2,31)-1; 
		for(int i=1;i<=n;i++){
			p = p & a[i];
		}
		ans = p; 
	}else{
		int p=pow(2,31)-1; 
		ans = dfs(1,0,p);
	} 
	cout<<ans; 
	return 0;
}
