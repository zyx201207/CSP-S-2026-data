#include<bits/stdc++.h> 
using namespace std;
long long a[2000005];
long long n,d;
long long sum=0;
long long minn=9999999;
void dfs(int l,int r,int s){
	if(l==r){
		if(s>minn) return;
		else if(s==minn){
			++sum;
			return;
		}
		else if(minn>s){
			minn=s;
			sum=1;
			return;
		}
	}
	int p=l+1;
	while(true){
		if(p<=r&&a[p]-a[l]<=d){
			dfs(p,r,s+1);
			++p;
		}
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=9999999;
				sum=0;
				dfs(i,j,0);
				if(sum==2) ++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}



