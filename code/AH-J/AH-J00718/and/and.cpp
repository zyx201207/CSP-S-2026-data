#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans,maxn,sum;
ll a[200010],max_sum;
bool vis[200010];
void dfs(ll s,ll p){
	if(s==m){
		ans=max(p,ans);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(s==0){
				vis[i]=1;
				dfs(s+1,a[i]);
				vis[i]=0;
			}else{
				vis[i]=1;
				dfs(s+1,p&a[i]);
				vis[i]=0;
			}
		}
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0);
		cout<<ans;
	}else{
		if(m==n){
			sum=a[1];
			for(int i=2;i<=n;i++){
				sum=sum&a[i];
			}
			cout<<sum;
		}else if(m==1){
			sort(a+1,a+1+n);
			cout<<a[n];
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						max_sum=max(max_sum,a[i]&a[j]);
					}
				}
			}
			cout<<max_sum;
		}else{
			sort(a+1,a+1+n);
			sum=a[n];
			for(int i=n-1;i>=n-m+1;i++){
				sum=sum&a[i];
			}
			cout<<sum;
		}
	}
	return 0;
}
