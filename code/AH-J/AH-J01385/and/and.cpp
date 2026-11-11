#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int ans=0;
string s[200010];
int t[200010];
void dfs(int i,int cnt,int he){
	if(cnt==m){
		ans=max(ans,he);
		return;
	}
	if(i>n || cnt+(n-i+1)<m){
		return;
	}
	if(cnt==0)
		dfs(i+1,cnt+1,a[i]);
	else
		dfs(i+1,cnt+1,he&a[i]);
	dfs(i+1,cnt,he);
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
	sort(a+1,a+1+n);
	if(n<=20){ //1~5
		dfs(1,0,0);
		cout<<ans;
	}else if(m==1){//6
		cout<<a[n];
	}else if(m==n){//7
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==2){//8~10
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n-1){//11,12
		int he=a[1];
		for(int i=2;i<=n;i++){
			he&=a[i];
		}
		for(int i=1;i<=n;i++){
			int now=a[i];
			int j=0;
			while(now!=0){
				s[i]+=now%2+'0';
				t[j]+=now%2;
				now/=2; j++;
			}
		}
		for(int i=1;i<=n;i++){
			int now=he;
			int len=s[i].size();
			for(int j=0;j<len;j++){
				if(s[i][j]=='1'&&t[j]==1){
					now-=(1<<j);
				}
			}
			ans=max(ans,now);
		}
		cout<<ans;
	}else{ //A
		cout<<a[n-m+1];
	}
	return 0;
}
