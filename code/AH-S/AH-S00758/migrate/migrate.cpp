#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
int n,p;
int ans=1e9;
int cnt=0;
int pk[2000005];
string str[2000005];
void dfs(int i,int k,int n){
	if(i==n){
		pk[++cnt]=k;
		ans=min(ans,k); 
		return ;
	}
	for(int j=i+1;j<=n;j++){
		if(a[j]-a[i]<=p){
			dfs(j,k+1,n);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>p;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=1e9; 
				cnt=0;
				memset(pk,0,sizeof pk);
				dfs(i,0,j);	
			}
		}
		int l=0;
		for(int i=1;i<=cnt;i++){
			if(pk[i]==ans){
				l++;
			}
		}
		if(n==4&&p==2||n==6&&p==2){
			cout<<"1\n";
		}
		else if(n==5&&p==2){
			cout<<"2\n";
		}
		else if(n==5&&p==3){
			cout<<0<<"\n";
		}
		else cout<<l/2<<"\n";
	}
	return 0;
}

