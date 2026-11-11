#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int x,y,su;
}f[200005];
int n,m,a[200005],dp[200005][10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	m--;
	for(int i=1;i<=m;i++){
		int k=0,l=0;
		dp[n][1]=0;
		for(int j=n-1;j>0;j--){
			int sum=0;
			int x=a[j],y=a[j+1];
			if(x==f[j].x&&y==f[j].y){
				sum=f[j].su;
			}else{
				int cur=0;
			    while(max(x,y)>0){
			    	if(x%2==1&&y%2==1){
				    	sum+=pow(2,cur);
				    }
				    x/=2,y/=2;
				    cur++;
			    }
				f[j].x=a[j];
				f[j].y=a[j+1];
				f[j].su=sum;
			}
			dp[j][2]=max(dp[j+1][1],sum);
			if(dp[j][2]==sum){
				k=j,l=j+1;
			}
			dp[j][1]=dp[j][2];
		}
		a[k]=dp[1][2];
		for(int j=l;j<n;j++){
			a[j]=a[j+1];
		}
		n--;
	}
	cout<<dp[1][2];
	return 0;
}
