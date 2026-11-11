//GZ-S00357 贵阳实验二中 刘子墨
#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,ans,k,p,dp[500005],q;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	q=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=q) q=0;
	}
	sort(a+1,a+n+1);
	if(q && a[2]-a[1]==1){
		k=1;
		while(m>=0 && n>0){
			m-=k++;
			ans++;
			n--;
		}
		cout<<ans;
		return 0;
	}
	else if(q){
		long long g=a[2]-a[1];
		k=g;
		while(m>=0 && n>=0){
			m-=k;
			k+=g;
			ans++,n--;
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=n;i>=2;i--){
			bool f=0;
			for(int j=i;j<=n;j++){
				for(int l=j-1;l>j-i;l--) dp[j]+=a[j]-a[l];
				if(dp[j]<=m) f=1,ans=i;
			}
			if(f) break;
		}
	}
	cout<<ans;
	return 0;
} 
