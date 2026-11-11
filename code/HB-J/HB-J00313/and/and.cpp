#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m;
ll a[N];
ll sum;
void dfs(int s,int now,ll t){
	if(now==0){
		sum=max(t,sum);
		return;
	}
	for(int i=s+1;i<=n-now+1;i++){
		dfs(i,now-1,(t&a[i]));
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==m){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		printf("%lld",sum);
		return 0;
	}
	if(n-1==m){
		sum=a[1];
		ll qian[N]={0};
		qian[1]=a[1];
		for(int i=2;i<=n;i++){
			qian[i]=(qian[i-1]&a[i]);
		}
		ll hou[N]={0};
		hou[n]=a[n];
		for(int i=n-1;i>=1;i--){
			hou[i]=(hou[i+1]&a[i]);
		}
		sum=max(hou[2],qian[n-1]);
		for(int i=2;i<n;i++){
			sum=max(sum,(qian[i-1] & hou[i+1]));
		}
		printf("%lld",sum);
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			sum=max(sum,a[i]);
		}
		printf("%lld",sum);
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i,m-1,a[i]);
	}
	printf("%lld",sum);
	return 0;
}
