#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005],s[200005],s2[200005];
void dfs(int p,int shu,int sum){
	if(p>n){
		if(shu==m){
			ans=max(ans,sum);
		}
		return;
	}
	if(sum!=0){
		dfs(p+1,shu+1,sum&a[p]);
		dfs(p+1,shu,sum);
	}
	else{
		if(shu==0){
			dfs(p+1,shu+1,sum+a[p]);
			dfs(p+1,shu,sum);
		}
		else{
			return;
		}
	}
	
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			s[i]=a[i];
			continue;
		}
		s[i]=s[i-1]&a[i];
		
	}
	for(int i=n;i>=1;i--){
		if(i==n){
			s2[n]=a[n];
			continue;
		}
		s2[i]=s2[i+1]&a[i];
		
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		s[0]=s2[2];
		s2[n+1]=s[n-1];
		for(int i=1;i<=n;i++){
			ans=max(ans,s[i-1]&s2[i+1]);
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
	
	return 0;
}
