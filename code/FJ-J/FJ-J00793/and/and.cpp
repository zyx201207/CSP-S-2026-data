#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[3000],b[3000];
bool f[3000];
long long dfs(int k){
	long long ans=INT_MIN;
	for(int i=0;i<n;i++){
		if(!f[i]){
			b[k]=a[i];
			f[i]=true;
			if(k==m-1){
				long long res=b[0];
				for(int i=1;i<m;i++){
					res&=b[i];
				}
				ans=max(ans,res);
			}else ans=max(ans,dfs(k+1));
			f[i]=false;
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}else if(m==n){
		long long ans=a[0];
		for(int i=1;i<n;i++) ans&=a[i];
		cout<<ans;
	}else if(m==2){
		long long res=INT_MIN;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				res=max(res,a[i]&a[j]);
			}
		}
		cout<<res;
	}else{
		cout<<dfs(0);
	}
	return 0;
}
