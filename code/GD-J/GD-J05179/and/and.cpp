#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,m;
int dp[N],a[N],f[N];
int yu(int a,int b){
	int er[100],p=1;
	while(!(a==0&&b==0)){
		if(a%2==b%2&&a%2==1){
			er[p]=1;
		}else{
			er[p]=0;
		}
		a/=2;
		b/=2;
		p++;
	}
	int an=0,mi=1;
	for(int i=1;i<=p;i++){
		an+=er[i]*mi;
		mi<<=1;
	}
//	for(int i=1;i<=p;i++){
//		cout<<er[i]<<" ";
//	}
	return an;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	int maxx=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[maxx]<a[i]){
			maxx=i;
		}
	}
	dp[1]=a[maxx];
	f[maxx]=1;
	int k=1;
	while((++k)<=m){
		int id;
		for(int i=1;i<=n;i++){
			if(!f[i]){
				int kk=yu(dp[k-1],a[i]);
				if(kk>dp[k]){
					dp[k]=kk;
					id=i;
				}
			}
		}
		f[id]=1;
		//cout<<a[id]<<" ";
	}
	cout<<dp[m];
	return 0;
}
//5 3
//31 3 1 15 7
