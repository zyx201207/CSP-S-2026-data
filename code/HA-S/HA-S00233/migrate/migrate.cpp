#include<bits/stdc++.h>
using namespace std;

int n;
long long d;
long long a[2000005];
int mn=2e6,cnt=0;

void dfs(int e,int pos,int s){
	if(pos==e){
		if(s==mn) cnt++;
		if(s<mn){
			mn=s;
			cnt=1;
		}
		return;
	}
	
	for(int i=pos+1;i<=e;i++){
		if(a[i]-a[pos]<=d)
			dfs(e,i,s+1);
	}
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=9){
			long long ans=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					mn=2e6,cnt=0;
					dfs(j,i,0);
					if(cnt==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
