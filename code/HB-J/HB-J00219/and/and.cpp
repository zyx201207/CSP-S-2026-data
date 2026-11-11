#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,a[200010]={ },b[200010]={ },cnt;
bool vis[200010]={ };
int js(int k){
	int i=1;
	for(int j=0;j<k;j++)i*=2;
	return i;
}
int awy(int x,int y){
	int f=0;
	for(int i=0;x!=0&&y!=0;i++){
		if(x%2==y%2&&x%2==1){
			f+=js(i);
		}
		x/=2,y/=2;
	}
	return f;
}
void dfs(int de){
	if(de==m){
		cnt=b[0];
		for(int i=1;i<m;i++){
			cnt=awy(cnt,b[i]);
		}
		ans=max(ans,cnt);
	}
	else {
		bool pd=1;
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				pd=0;
				vis[i]=1;
				b[de]=a[i];
				dfs(de+1);
			}
			if(pd==0)vis[i]=0;
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans=awy(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)ans=max(ans,awy(a[i],a[j]));
		cout<<ans;
		return 0;
	}
	else dfs(0);
	cout<<ans;
	return 0;
}
