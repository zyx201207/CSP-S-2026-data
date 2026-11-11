#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long c[200010];
long long s[200010];
struct Q{
	long long nm;
	int k;
};
int vis[200010];
long long bfs(long long mn,int K){
	long long ans=0;
	queue<Q> q;
	q.push({mn,K});
	while(!q.empty()){
		long long nam=q.front().nm;
		int ak=q.front().k;
		q.pop();
		if(ak==0){
			if(ans<nam) ans=nam;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]!=1&&(nam&a[i])>ans){
				vis[i]=1;
				q.push({(nam&a[i]),ak-1});
				vis[i]=0;
			}
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>maxn){
					maxn=(a[i]&a[j]);
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		c[1]=a[1];
		s[n]=a[n];
		for(int i=2;i<=n;i++){
			c[i]=(c[i-1]&a[i]);
		}
		for(int i=n-1;i>=1;i--){
			s[i]=(s[i+1]&a[i]);
		}
		long long maxn=0;
		for(int i=1;i<=n;i++){
			long long num=(c[i-1]&s[i+1]);
			if(i==1){
				num=s[2];
			}
			if(i==n){
				num=c[n-1];
			}
			if(num>maxn){
				maxn=num;
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		c[1]=a[1];
		for(int i=2;i<=n;i++){
			c[i]=(c[i-1]&a[i]);
		}
		cout<<c[n];
		return 0;
	}
	if(n<=20){
		long long ans=bfs(1048575,m);
		cout<<ans;
		return 0;
	}
	int f=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) f=0;
	}
	if(f){
		long long ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	long long maxn=0;
	for(int i=1;i<=n;i++){
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	cout<<maxn;
	return 0;
}
