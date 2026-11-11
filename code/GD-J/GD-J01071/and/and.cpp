#include<bits/stdc++.h>
using namespace std;
int n,m,dp[200000];
struct data{
	int b,r;
}a[200000];
int cmp(data a,data b){
	return a.r>b.r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
		int x=a[i].b;
		a[i].r=0;
		while(x>0){
			if(x%2==1){
				a[i].r++;
			}
			x/=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		dp[i]=a[1].b;
	}
	int maxn=-1;
	if(m==1){
		cout<<a[1].b;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				int y;
				if(i==1&&j==1){
					y=a[2].b;
				}else{
					y=a[1].b;
				}
				y=y&a[i].b; 
				maxn=max(maxn,y);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int x=a[1].b;
		for(int i=2;i<=n;i++){
			x=x&a[i].b;
		}
		cout<<x;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i].b&a[j].b);
			}
		}
		cout<<maxn;
		return 0;
	}
	for(int k=2;k<=m;k++){
		for(int i=k;i<=n;i++){
			dp[i]=dp[i]&a[i].b;
			maxn=max(maxn,dp[i]);
		}
		for(int i=k;i<=n;i++){
			dp[i]=maxn;
		}
		maxn=-1;
	}
	cout<<dp[n];
	return 0;
}

