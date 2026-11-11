#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long res;
long long a[200005],f[5005][5005],dp[5005][5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	} 
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			f[i][j]=a[i]-a[j];
//			cout<<"f["<<i<<"]"<<"["<<j<<"]=="<<f[i][j]<<" ";
		}
	}
//	cout<<"\n";
	for(int i=n;i>=1;i--){
		long long tt=m,ans=1;
		for(int j=i-1;j>=1;j--){
//			cout<<"i="<<i<<"j="<<j<<" "<<"tt="<<tt<<"f[i][j]="<<f[i][j]<<endl;
			if((tt-f[i][j]>=0)){
				ans++;
				tt-=f[i][j];
			}
		}
		res=max(res,ans);
	}
	printf("%lld\n",res);
	return 0;
}
