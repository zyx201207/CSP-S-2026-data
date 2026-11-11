#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
const int N=2e5+5;
int n,m;
int ans=-1e18;
int maxi=-1e18;
int a[N];
bool vis[N];
void dfs(int x,int sum){
	if(x>n){
		if(sum==m){
			bool f=0;
			int tmp=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					if(f==0){
						tmp=a[i];
						f=1;
					}else{
						tmp&=a[i];
					}
				}
			}
			maxi=max(maxi,tmp);
			return ;
		}
		return ;
	}
	vis[x]=1;
	dfs(x+1,sum+1);
	vis[x]=0;
	dfs(x+1,sum);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	if(n<=20){
		dfs(1,0);
		cout<<maxi;
	}else if(n>20&&n<=2000){
		if(m==1){
			cout<<ans;
		}else if(m==n){
			int sum=a[1];
			for(int i=2;i<=n;i++){
				sum&=a[i];
			}
			cout<<sum;
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					maxi=max(maxi,(a[i]&a[j]));
				}
			}
			cout<<maxi;
		}
	}else{
		if(m==n-1){
			for(int i=1;i<=n;i++){
				bool f=0;
				int tmp=0;
				for(int j=1;j<=n;j++){
					if(j==i){
						continue;
					}
					if(f==0){
						tmp=a[j];
						f=1;
					}else{
						tmp&=a[j];
					}
				}
				maxi=max(maxi,tmp);
			}
			cout<<maxi;
		}
	}
	return 0;
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12
*/
