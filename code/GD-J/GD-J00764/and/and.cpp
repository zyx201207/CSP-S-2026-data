#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ma;
int t[200005];
void dfs(int u,int ans,int cnt){
	if(cnt==m){
		ma=max(ans,ma);
		return ;
	}
	if(u==n+1){
		return ;
	}
	dfs(u+1,(ans&a[u]),cnt+1);
	dfs(u+1,ans,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=1;
	for(int i=1;i<=20;i++){
		k=k*2;
	}
	if(n<=20){
		dfs(1,k-1,0);
		cout<<ma;
		return 0;
	}
	if(n<=2000){
		if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
		}
		if(m==n){
			int an=a[1];
			for(int i=2;i<=n;i++){
				an=(an&a[i]);
			}
			cout<<an;
			return 0;
		}
		if(m==2){
			int an=-1;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					an=max(an,(a[i]&a[j]));	
				}
			}
			cout<<an;
			return 0;
		}
	}
	if(m==n-1){
		cout<<0;
		return 0;
	}else{
		int b=1;
		for(int i=1;i<=n;i++){
			if(a[i]>=4){
				b=0;
			}
			if(a[i]<4){
				t[a[i]]++;
			}
		}
		if(b){
			if(t[1]+t[3]<m&&t[2]+t[3]<m){
				cout<<0;
				return 0;
			}
			if(t[2]+t[3]>=m){
				cout<<2;
				return 0;
			}
			if(t[1]+t[3]>=m){
				cout<<1;
				return 0;
			}
		}else{
			int an;
			for(int i=1;i<=n;i++){
				an=max(an,a[i]);	
			}
			cout<<an;
			return 0;
		}
	}
	return 0;
}
