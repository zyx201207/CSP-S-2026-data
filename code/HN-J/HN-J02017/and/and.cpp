#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,m;
long long a[N];
long long sum=-10;
long long ans=-100000;
bool j[N];
void dfs(int cnt){
	if(cnt==m){
		sum=-10;
		for(int i=1;i<=n;i++){
			if(j[i]==1){
				if(sum==-10)sum=a[i];
				else sum=(sum&a[i]);
			}
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)if(!j[i]){
		j[i]=1;
		dfs(cnt+1);
		j[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m!=1){
		sum=a[1];
		dfs(0);
		cout<<ans;
	}else if(m==1){
		long long ans=-1; 
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==n){
		int sum=a[1];
		for(int i=1;i<=n;i++)sum=(sum&a[i]);
		cout<<sum;
	}
	return 0;
}
