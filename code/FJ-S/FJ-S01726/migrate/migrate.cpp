#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a[2000009];
bool check(int l,int r){
	int dp[2000009],f[2000009];
	for(int i=l;i<=r;i++){
		dp[i]=r-l+1;
		f[i]=0;
	}dp[l]=0;
	f[l]=1;
	for(int i=l+1;i<=r;i++){
		for(int j=i-1;j>=l;j--){
			if(a[i]-a[j]>d)break;
			if(dp[i]>dp[j]+1){
				dp[i]=dp[j]+1;
				f[i]=0;
			}else if(dp[i]==dp[j]+1){
				f[i]+=f[j];
			}
		}
	}if(f[r]==2)return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		long long ans,f1;
		bool f=1;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]&&f){
				f=0;
			}
		}if(f){
			int x=a[2]-a[1],k=1;
			x/=d;
			if(x<=1){
				printf("0\n");	
			}else{
				printf("%d\n",n-(2*x)+1);
			}continue;	
		}for(int i=1;i<=n;i++){
			if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
				f1=i;
				break;
			}
		}if(f1){
			int l=1,r=f1+1;
			while(l<=r&&l<f1&&r<=n){
				if(a[r]-a[l]<d)r++;
				else{
					if(r-l-1==2)ans++,l++;
				}
			}printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j))ans++;
			}
		} printf("%d\n",ans);
	}
	return 0;
}
