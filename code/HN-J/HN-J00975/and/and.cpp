#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n,m;
int a[maxn];
bool vis[maxn]; 
int pre[maxn],suf[maxn];
int answer=0;
void dfs(int x,int cnt){
	if(cnt>m) return ;
	if(x>n){
		int k=0;
		int st=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				k=a[i];
				st=i+1;
				break;
			}
		}
		for(int i=st;i<=n;i++){
			if(vis[i]){
				k=(k&a[i]);
			}
		}
		if(cnt==m){
			answer=max(answer,k);
		}
		return ;
	}
	vis[x]=false;
	dfs(x+1,cnt);
	vis[x]=true;
	dfs(x+1,cnt+1);
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(n<=20){
		dfs(1,0);
		cout<<answer;
		return 0;
	} 
	else if(m==1){
		int maxi=0;
		for(int i=1;i<=n;i++) maxi=max(maxi,a[i]);
		cout<<maxi;
		return 0; 
	}
	else if(m==2&&n<=5000){
		int maxi=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxi=max(maxi,(a[i]&a[j]));
			}
		} 
		cout<<maxi;
		return 0;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans=(ans&a[i]);
		cout<<ans;
		return 0; 
	}
	else if(m==n-1){
		pre[1]=a[1],suf[n]=a[n];
		for(int i=2;i<=n;i++){
			pre[i]=(pre[i-1]&a[i]);
		}
		for(int i=n-1;i>=1;i--){
			suf[i]=(suf[i+1]&a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i==1){
				ans=max(ans,suf[i+1]);
			}
			else if(i==n){
				ans=max(ans,pre[n-1]);
			}
			else{
				ans=max(ans,(pre[i-1]&suf[i+1]));
			}
		}
		cout<<ans;
	}
	else{
		bool flag=true;
		for(int i=1;i<=n;i++){
			bool ok=false;
			for(int j=0;j<=30;j++){
				if((1ll<<j)-1==a[i]){
					ok=true;
					break;
				}
			}
			if(!ok){
				flag=false;
				break;
			}
		}
	    if(flag){
	    	cout<<a[n-m+1];
	    	return 0;
		}
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
