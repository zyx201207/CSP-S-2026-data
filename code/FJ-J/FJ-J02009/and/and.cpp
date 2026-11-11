#include<iostream>
#include<cstdio>
using namespace std;
int n,m,f,cs,b=2,maxn;
int a[200005];
bool o=0;
bool q[200005];
int dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(dp[1]<a[i]){
			dp[1]=max(dp[1],a[i]);
			q[cs]=0;
			cs=i;
			q[cs]=1;
		}
	}
	if(m==1){
		cout<<dp[1];
		return 0;
	}
	if(n==m){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;        
		return 0;
	}
	while(b<=m){
		for(int i=1;i<=n;i++){
			if(q[i]==0){
				dp[b]=max(dp[b],dp[b-1]&a[i]);
				q[cs]=0;
				cs=i;
				q[cs]=1;
			}
		}
		b++;
	}
	cout<<dp[m];
}
