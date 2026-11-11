#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000010],d,dp[1000010]={0},dpq[1000010]={0},c,z,x=1,maxx;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>m;
	for(int ii=0;ii<m;ii++){
	cin>>n>>d;
	z=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	
	for(int k=1;k<n-d;k++){
		for(int j=n;j>=k+1;j--){
		dp[k]=1;
	dpq[k]=1;
	for(int i=k;i<=j;i++){
		if(a[i]<=d){
		dp[a[i]]=1;	
		}else{
			if(a[i]%2!=k%2){
		dp[a[i]]=dpq[a[i-1]]-dpq[a[i]-d-1];}else{
			if(a[i]-d-1%2==k%2){
				dp[a[i]]=dpq[a[i-1]]-dpq[a[i]-d-1];
			}else{
				dp[a[i]]=0;
			}
		}
		}dpq[a[i]]=dp[a[i]]+dpq[a[i]-1];//cout<<dp[a[i]]<<" "<<dpq[a[i]]<<endl;
	}	if(dp[a[j]]==2){
		z++;	
		}//cout<<dp[a[j]]<<endl<<endl;
	}
	}cout<<z;
}	
}/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5*/

