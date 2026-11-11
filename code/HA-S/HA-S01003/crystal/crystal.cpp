#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,xx;
long long m,a[500005],sum;
bool f[500005];
void dfs(int k,long long w){
	if(w==0){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(i!=k&&w-abs(a[i]-xx)>=0&&f[i]==0){
			w-=abs(a[i]-xx);
			ans++;
			sum=max(sum,ans);
			f[i]=1;
			dfs(i,w);
			w+=abs(a[i]-xx);
			f[i]=0;
			ans--;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long w=m,xx=a[i];
		for(int j=1;j<=n;j++){
			f[j]=0;
		}
		ans=0;
		dfs(i,w);
	}
	cout<<sum+1;
	return 0;
}
