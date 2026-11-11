#include<bits/stdc++.h>
using namespace std;
long long ans=-1e9,n,m,a[100000],b[100000],kk=-1e9,sumo[1000000],sum[1000000];
void dfs(long long x,long long y){
	if(y==m){
		long long sum=b[1];
		for(int i=2;i<=m;i++){
			sum&=b[i];
		}
		ans=max(ans,sum);
		return ;
	}
	if(x>n)return ;
	b[y+1]=a[x];
	dfs(x+1,y+1);
	dfs(x+1,y); 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		kk=max(kk,a[i]);
	}
	if(n<=30){
		dfs(1,0);
		cout<<ans;
	}else if(m==n-1){
		for(int i=2,j=n-1;i<=n;j--,i++){
			sumo[i]=sumo[i-1]&a[i];
			sum[j]=sum[j+1]&a[i];
		}
		for(int i=1;i<=n;i++){
			if(i==1){
				ans=max(ans,sum[i+1]);
			}
			else if(i==n){
				ans=max(ans,sumo[i-1]);
			}
			else{
				ans=max(ans,sum[i+1]&sumo[i-1]);
			}
		}
	}else{
		cout<<kk;
	}
	return 0; 
}
