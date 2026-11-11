#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005];
long long ans;
bool vis[200005];
long long answe(){
	long long res=b[1];
	for(int i=2;i<=m;i++){
		res=(res&b[i]);
	}
	return res;
}
void bfs(int t){
	for(int i=1;i<=n;i++){
		if(t>m){
			ans=max(ans,answe());
			return;
		} 
		if(vis[i]==0){
			vis[i]=1;
			b[t]=a[i];
			bfs(t+1);
			bfs(t);	
			vis[i]=0;		
		}

		
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(m==1){
		cout<<maxa;
		return 0;
	} 
	if(m==2){
		maxa=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxa=max(maxa,(a[i]&a[j]));
			}
		}
		cout<<maxa;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	
	bfs(1);
	cout<<ans;
	return 0;
}
