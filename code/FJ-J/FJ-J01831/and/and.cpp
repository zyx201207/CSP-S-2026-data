#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-1;
bool vis[200005];
bool check(long long s[]){
	for(int i=1;i<=n;i++)if(s[i]>=4)return false;
	return true;
}
void dfs(long long cnt,int step){
	if(step>=m){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(cnt&a[i],step+1);
			vis[i]=false;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)for(int i=1;i<=n;i++)ans=max(ans,a[i]);
	else if(m==n){ans=a[1];for(int i=2;i<=n;i++)ans=ans&a[i];}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else if(m==n-1){
		ans=a[1];for(int i=2;i<=n;i++)ans=ans&a[i];
		long long cnt=-1;
		for(int i=1;i<=n;i++)cnt=max(cnt,ans^a[i]);
		ans=cnt;
	}
	else if(n<=20){
		dfs(2147483647,0);
	}
	else if(check(a)){
		sort(a+1,a+n+1);
		ans=3;int a1=0,b1=0,c1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3)c1++;
			if(a[i]==2)b1++;
			if(a[i]==1)a1++;
		}
		if(c1<m)ans--;
		if(c1+b1<m)ans--;
	}
	else{
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n;i>=n-m+1;i--){
			ans=min(ans,a[i]);
		}
	}
	cout<<ans;
	return 0;
}
