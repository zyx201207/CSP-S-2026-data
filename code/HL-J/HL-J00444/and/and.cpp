#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans,b[200005];
bool used[200005];
long long n,m;
void dfs(int k){
	if(k==m+1){
		long long sum=a[1];
		for(int i=2;i<=m;i++) sum=sum&b[i];
		ans=max(ans,sum);
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=true;
			b[k++]=a[i];
			dfs(k);
			used[i]=false;
			b[k]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else{
		dfs(1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
