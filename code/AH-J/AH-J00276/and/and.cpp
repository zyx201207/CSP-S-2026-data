#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],vis[25];
int b[25],ans,q,maxnp=-0x3f3f3f3f;
void dfs(int id,int cnt){
	if(id>n||cnt>m){
		for(int i=1;i<=q;i++){
			cout<<b[i]<<" ";
		}
		int xqw=b[1];
		for(int i=2;i<=q;i++){
			xqw&=b[i];
		}
		ans=max(ans,xqw);
		q=0;
		cout<<endl;
		return ;
	}
	dfs(id+1,cnt);
	b[++q]=a[id];
	dfs(id+1,cnt+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		int maxn=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	int ans=-1;
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max((a[i]&a[j]),ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		cin>>a[1];
		int xo_r=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			xo_r&=a[i];
		}
		cout<<xo_r;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			int k;
			if(i==1){
				k=a[2];
				for(int j=3;j<=n;j++){
					k&=a[j];
				}
			}else{
				if(i==2){
					k=a[1];
				}else if(i==n){
					k=a[1];
					for(int j=2;j<=n-1;j++){
						k&=a[j];
					}
				}else{
					k=a[1];
					for(int j=2;j<=i-1;j++){
						k&=a[j];
					}
					for(int j=i+1;j<=n;j++){
						k&=a[j];
					}
				}
			}
			ans=max(ans,k);
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxnp=max(a[i],maxnp);
	}
	if(maxnp==3){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
