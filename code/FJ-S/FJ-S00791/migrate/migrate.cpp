#include<bits/stdc++.h>
using namespace std;
int s=0x3f3f3f3f;
int cnt;
long long a[201010];
int d;
void dfs(int x,int r,int p){
	if(x==r){
		if(p<s){
			cnt=0;
			s=p;
		}
		if(s==p){
			cnt++;
		}
		return;
	}
	for(int i=x+1;i<=r;i++){
		if(a[i]-a[x]<=d){
			dfs(i,r,p+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[j]-a[i]<=d){
					continue;
				}
				cnt=0;
				s=0x3f3f3f3f;
				dfs(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

