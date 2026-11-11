#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,cur;
void dfs(int k,int cnt,int res){
	if(k>n||cnt>=m){
		if(cnt==m) ans=max(ans,res);
		return;
	}
	dfs(k+1,cnt,res);
	if(!res) dfs(k+1,cnt+1,a[k]);
	else dfs(k+1,cnt+1,res&a[k]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	if(n<=2000){
		if(m==2) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
		else if(m==1) for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		else{
			ans=a[1];
			for(int i=2;i<=n;i++) ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	if(a[n]<=4){
		for(int i=1;i<=n;i++) if(a[i]==4) cur++;
		if(cur>=m){
			cout<<4;
			return 0;
		}
		cur=0;
		for(int i=1;i<=n;i++) if(a[i]==3) cur++;
		if(cur>=m){
			cout<<3;
			return 0;
		}
		cur=0;
		for(int i=1;i<=n;i++) if(a[i]==2||a[i]==3) cur++;
		if(cur>=m){
			cout<<2;
			return 0;
		}
		cur=0;
		for(int i=1;i<=n;i++) if(a[i]==1||a[i]==3) cur++;
		if(cur>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
}
//I love luiyin and xiadie
