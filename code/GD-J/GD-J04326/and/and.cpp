#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,m,a[N],ans=(1<<40)-1;
bool f[N][40],vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(long long j=0;j<=32;j++){
			if(a[i]&(1ll<<j)) f[i][j]=true;
		}
	for(int i=32;i>=0;i--){
		long long sum=0;
		for(int j=1;j<=n;j++){
			if(!vis[j])
				sum+=f[j][i];
		}
		if(sum>=m){
			for(int j=1;j<=n;j++)
				if(!f[j][i]) vis[j]=true;
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) ans&=a[i],sum++;
		if(sum==m) break;
	}
	cout<<ans;
	return 0;
}
