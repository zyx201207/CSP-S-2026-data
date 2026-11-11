#include<bits/stdc++.h>
using namespace std;
int n,m,t[37];
struct S{
	int v,z;
	bool q[37];
}a[200007];
bool vis[200007];
bool cmp(S x,S y){
	if(x.z!=y.z) return x.z>y.z;
	int l=x.z,r=y.z;
	while(x.q[l]==y.q[r]){
		l--,r--;
	}
	if(x.q[l]==0) l=-1;
	else l=40;
	return l>r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=n;i++) cin>>a[i].v;
		long long ans=0;
		for(int i=1;i<=pow(2,20);i++){
			int x=i,cnt=1,s=0,l=0;
			while(x>0){
				if(x&1){
					if(l==0) s=a[cnt].v;
					else s&=a[cnt].v;
					l++;
				}
				x/=2;
				cnt++;
				if(l==m){
					ans=max(ans,(long long)s);
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].v;
			ans=max(ans,a[i].v);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++) cin>>a[i].v;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i].v&a[j].v);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++) cin>>a[i].v;
		int ans=a[1].v;
		for(int i=2;i<=n;i++) ans&=a[i].v;
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int dp[200007][2];
		for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].v;
			dp[i][0]=dp[i-1][1];
			dp[i][1]=dp[i-1][1]&a[i].v;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,dp[i][0]);
		}
		cout<<ans;
		return 0;
	}
//	for(int i=1;i<=n;i++){
//		cin>>a[i].v;
//		int x=a[i].v,cnt=1;
//		while(x>0){
//			if(x&1){
//				t[cnt]++;
//				a[i].q[cnt]=1;
//			}
//			x/=2;
//			cnt++;
//		} 
//		a[i].z=cnt-1;
//	}
//	sort(a+1,a+n+1,cmp);
//	for(int i=31;i>=1;i--){
//		if(t[i]<=1) continue;
//		for(int i=1;i<=min(m,t[i]/2*2);i++){
//			
//		} 
//	}
	return 0;
}
