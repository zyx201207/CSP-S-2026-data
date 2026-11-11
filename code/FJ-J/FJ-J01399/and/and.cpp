#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long num=-1;
bool vis[200005];
void dfs(int cnt,long long sum){
	if(cnt==m){
		num=max(num,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(cnt==0){
			vis[i]=true;
			dfs(cnt+1,a[i]);
			vis[i]=false;
		}else if(!vis[i]){
			vis[i]=true;
			dfs(cnt+1,sum&a[i]);
			vis[i]=false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int h=0;
	int flag=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(i==1) h=a[i];
		else if(h!=a[i]) flag=1;
	}
	if(m==1) {
		long long mmax=-1;
		for(int i=1; i<=n; i++) {
			mmax=max(mmax,a[i]);
		}
		cout<<mmax;
	}else if(m==n){
		long long sum=a[1];
		for(int i=2; i<=n; i++) {
			sum&=a[i];
		}
		cout<<sum;
	}else if(m==2){
		long long mmax=-1;
		for(int i=1; i<n; i++) {
			for(int j=i+1;j<=n;j++){
				mmax=max(mmax,a[i]&a[j]);
			}
		}
		cout<<mmax;
	}else if(n<=20){
		dfs(0,0);
		cout<<num;
	}else if(flag){
		cout<<a[1];
	}
	return 0;
}
