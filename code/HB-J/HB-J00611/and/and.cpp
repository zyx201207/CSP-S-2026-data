#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],maxn;
void dfs(int x){
	if(x==m){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				if(sum==0) sum=a[i];
				else sum=sum&a[i];
			}
		}
		maxn=max(maxn,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			dfs(x+1);
			b[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++)sum=sum&a[i];
		cout<<sum;
	}
	else{
		dfs(0);
		cout<<maxn;
	}
	return 0;
}
