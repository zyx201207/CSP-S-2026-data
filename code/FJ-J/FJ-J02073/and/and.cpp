#include<bits/stdc++.h>
using namespace std;
int a[200010];
int dp[200010];
long long f(long long x){
	long long sum=0;
	long long s=1;
	while(x!=0){
		sum+=(x-(x/2)*2)*s;
		s*=10;
		x/=2;
	}
	return sum;
}
long long ff(long long x,long long y){
	long long sum=0;
	long long s=1;
	while(min(x,y)!=0){
		int c=x%10;
		int d=y%10;
		if(c==d){
			sum+=c*s;
		}
		s*=10;
		x/=10;
		y/=10;
	}
	return sum;
}
long long fff(long long x){
	long long s=1;
	long long sum=0;
	while(x!=0){
		int c=x%10;
		sum+=c*s;
		s*=2;
		x/=10;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		a[i]=f(a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}else
	if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=ff(a[i],a[i-1]);
		}
		cout<<fff(a[n]);
	}else
	if(m==2){
		int maxn=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long s1=ff(a[i],a[j]);
				long long s2=fff(s1);
				if(s2>maxn){
					maxn=s2;
				}
			}
		}
		cout<<maxn;
	}else
	if(m==n-1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i)dp[j]=a[i];
				else dp[j]=0;
			}
			sort(dp+1,dp+n+1);
			for(int j=3;j<=n;j++){
				dp[j]=ff(dp[j],dp[j-1]);
			}
			maxn=max(maxn,dp[n]);
		}
		cout<<fff(maxn);
	}
	return 0;
} 
