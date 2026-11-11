#include<bits/stdc++.h>
using namespace std;
int n,m,a[233333],ans,v[22];
void dfs(int mx,int ct){
	if(ct==m){
		ans=max(ans,mx);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]++;
		dfs(mx&a[i],ct+1);
		v[i]--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<22){
		dfs(2147483647,0);
		cout<<ans;
		return 0;
	}else if(n<2222){
		if(m==1){
			for(int i=1;i<=n;i++) ans=max(ans,a[i]);
			cout<<ans;
			return 0;
		}else if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++) ans=ans&a[i];
			cout<<ans;
			return 0;
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
			}
			cout<<ans;
			return 0;
		}
	}else{
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	} 
	return 0;
}

