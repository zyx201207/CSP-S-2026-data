#include<bits/stdc++.h>
using namespace std;
int n,m,c=-999999;
const int N=2e5+10;
int a[N],f[N],b[N];
void dfs(int x){
	if(x>n){
		bool f=false;
		int cnt=0,d=0;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				cnt++;
				if(!f){
					d=a[i];
					f=true;
					continue;
				}
				d=d&a[i];
			}
		}
		if(cnt!=m){
			return;
		}
		c=max(c,d);
		return ;
	}
	for(int i=0;i<=1;i++){
		b[x]=i;
		dfs(x+1);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(m==1){
		int maxx=-999999;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int maxx=-999999;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1){
		int maxx=-999999,ans;
		for(int i=1;i<=n;i++){
			ans=a[1];
			if(i==1){
				ans=a[2];
			}
			for(int j=2;j<=n;j++){
				if(i!=j){
					ans=ans&a[j];
				}
			}
			maxx=max(maxx,ans);
		}
		cout<<maxx;
		return 0;
	}
	dfs(1);
	cout<<c;
	return 0;
}
