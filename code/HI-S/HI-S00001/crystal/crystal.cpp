#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],ans=-2e9;
void dfs(int cnt){
	if(cnt==m+1){
		map<int,int>mp;
		for(int i=1;i<=n;i++) mp[a[i]]++;
		int maxx=-2e9;
		for(auto it=mp.begin();it!=mp.end();it++){
			maxx=max(maxx,it->second);
		}
		ans=max(maxx,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(cnt+1);
		a[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool flag=true;
	int maxa=-2e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]-a[i-1])!=(a[2]-a[1])&&i>=2) flag=false;
		maxa=max(maxa,a[i]);
	}
	if(m<=1000){
		dfs(1);
		cout<<ans<<"\n";
	}
	else if(flag){
		for(int i=n;i>=1;i--){
			if(m<=a[n]-a[i]) break;
			else{
				a[i]=a[n];
				m-=(a[n]-a[i]);
			}
		}
		int ans=0;
		for(int i=n;i>=1;i--)  if(a[i]==a[n]) ans++;
		cout<<ans<<"\n"; 
	}
	else cout<<0<<"\n";
	return 0;
}
//oh no!!!!
