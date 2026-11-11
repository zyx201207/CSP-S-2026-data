#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
int a[200010],t[5];
int n,m;
void dfs(int now,int choose,int nans,int &ans,int allchoosing){
	if(now==n){
		if(allchoosing!=m)return;
		if(choose==1){
			ans=max(ans,(nans&a[now]));
		}else{
			ans=max(ans,nans);
		}
		return;
	}
	if(choose){
		if(nans==-1)nans=a[now];
		else nans=(nans&a[now]);
		dfs(now+1,1,nans,ans,allchoosing+1);
		dfs(now+1,0,nans,ans,allchoosing);
	}else{
		dfs(now+1,1,nans,ans,allchoosing+1);
		dfs(now+1,0,nans,ans,allchoosing);
	}
	return;
}
bool cmp(int a,int b){
	return a>b;
}
bool check(int a){
	int t=1;
	if(a==t-1)return 1;
	for(int i=1;i<=30;i++){
		t*=2;
		if(a==t-1)return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m<=20&&n<=20){
		int ans=0;
		dfs(1,1,a[1],ans,1); 
		dfs(1,0,-1,ans,0);
		cout<<ans;
		return 0;
	} 
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2&&n<=10000){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0; 
	}
	bool c=1;
	for(int i=1;i<=n;i++){
		c=min(c,check(a[i]));
		if(c==0)break;
	}
	if(c){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	
	if(m==n-1){
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=n-1;i>=2;i--){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	c=1;
	for(int i=1;i<=n;i++){
		c=min(c,(a[i]<=3));
		if(c==0)break;
	}
	if(c==1){
		for(int i=1;i<=n;i++){
			t[a[i]]++;
		}
		if(t[3]>=m)cout<<3;
		else{
			if(t[3]+t[2]>=m)cout<<2;
			else{
				if(t[3]+t[1]>=m)cout<<1;
				else cout<<0;
			}
		}
		return 0;
	}
	return 0;
} 
