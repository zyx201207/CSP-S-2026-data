#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200010],ans=-1,maxx,minn,res;
void dfs(int p,int cnt,int sum){
	if(p>n){
		if(cnt==m){
			ans=max(ans,sum);
		}
		return;
	}
	if(sum==-1){
		dfs(p+1,cnt,sum);
		dfs(p+1,cnt+1,a[p]);
	}
	else{
		dfs(p+1,cnt,sum);
		dfs(p+1,cnt+1,sum&a[p]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	if(n<=20){
		dfs(1,0,-1);
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		res=a[1];
		for(int i=2;i<=n;i++){
			res&=a[i];
		}
		cout<<res;
		return 0;
	}
	if(m==2&&n<=10000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>res){
					res=(a[i]&a[j]);
				}
			}
		}
		cout<<res;
		return 0;
	}
	if(m==n-1){
		if(a[1]==minn){
			res=a[2];
			for(int i=3;i<=n;i++){
				res&=a[i];
			}
		}
		else{
			bool f=1;
			res=a[1];
			for(int i=2;i<=n;i++){
				if(a[i]==minn&&f){
					f=0;
					continue;
				}
				res&=a[i];
			}
		}
		cout<<res;
		return 0;
	}
	sort(a+1,a+n+1);
	res=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		res&=a[i];
	}
	cout<<res;
	return 0;
}
