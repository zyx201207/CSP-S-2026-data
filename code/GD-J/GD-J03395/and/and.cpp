#include<bits/stdc++.h>
using namespace std;
long long a[200010],sum=0,ans;
int n,m;
void dfs(int i){
	sum++;
	if(sum==1){
		ans=a[i];
	}else{
		ans&=a[i];
	}
	for(int j=i+1;j<=n;j++){
		dfs(j);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			sum=0;
			dfs(i);
			maxn=max(maxn,ans);
		}
		cout<<maxn;
	}else{
		if(m==1){
			long long maxn=0;
			for(int i=1;i<=n;i++){
				maxn=max(maxn,a[i]);
			}
			cout<<maxn;
		}else if(m==2){
			long long maxn=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					maxn=max(maxn,a[i]&a[j]);
				}
			}cout<<maxn;
		}else if(m==n){
			long long sum=a[1];
			for(int i=2;i<=n;i++){
				sum&=a[i];
			}cout<<sum;
		}else{
			long long maxn=0;
			for(int i=1;i<=n;i++){
				sum=0;
				dfs(i);
				maxn=max(maxn,ans);
			}
			cout<<maxn;
		}
	}
	return 0;
}
