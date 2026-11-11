#include<bits/stdc++.h>
using namespace std;
long long a[200005],maxx=-1,mmax=-1,sum,ans;
int n,m,v[200005];
void dfs(int now,long long sum){
	if(now>m){
		if(sum>maxx){
			maxx=sum;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]!=1){
			v[i]=1;
			if(now==1){
				dfs(now+1,a[i]);
			}else{
				dfs(now+1,sum&a[i]);
			}
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmax=max(mmax,a[i]);
		if(i==1){
			sum=a[i];
		}else{
			sum&=a[i];
		}
	}
	if(n<=20){
		dfs(1,0);
		cout<<maxx;
		return 0;
	}else if(n<=2000&&m==1){
		cout<<mmax;
		return 0;
	}else if(n<=2000&&m==n){
		cout<<sum;
		return 0;
	}else if(n<=2000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>maxx){
					maxx=(a[i]&a[j]);
				}
			}
		}
		cout<<maxx;
		return 0;
	}else{
		sort(a+1,a+n+1);
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
