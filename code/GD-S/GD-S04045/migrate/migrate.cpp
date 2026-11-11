#include<bits/stdc++.h>
using namespace std;
long long n,d,c,t,a[2000010],ans;
void dfs(int j){
	int k=j+1;
	if(k>n) return;
	while(k<=n&&a[k]-a[j-1]<=d) k++;
	while(k<=n&&a[k]-a[j]<=d){
		k++;
		ans++;
	}
	dfs(k);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			int j=i+1;
			while(a[j]-a[i]<=d&&j<=n){
				j++;
			}
			int p=j-1;
			while(j<=n&&a[j]-a[p]<=d){
				int cnt=0,k=p;
				while(i<k&&a[j]-a[k]<=d){
					k--;
					cnt++;
				}
				if(cnt==2){
					ans++;
					dfs(j);
					break;
				}
				j++;		
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
