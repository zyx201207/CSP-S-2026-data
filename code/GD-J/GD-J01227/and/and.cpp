#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long dp[200010];
bool v[200010]={1};
bool cmp(int x,int y){
	return x>y;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout); 
	cin>>n>>m;
	long long w=-1;
	for(int i=1;i<=n;i++){			
		cin>>a[i];
		w=max(a[i],w);
	}
	long long y=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)
			y=max(y,(a[i]&a[j]));
		}
	}
	if(m==1){
		cout<<w;
		return 0;
	}
    if(m==2){
    	cout<<y;
    	return 0;
	}
	dp[1]=a[1];
	for(int i=1,l=2;i<=m;i++,l++){
		long long q=dp[i-1];
		long long p=dp[i-1];
		long long k;
		for(int j=2;j<=n;j++){
//			if(v[j]!=0){
				if((p&a[j])>q){
					q=(p&a[j]);
					k=j;
				}
//			} 
		}
		v[k]=0;
		dp[i]=max(dp[i-1],q);
		
	}
	cout<<dp[m];
	return 0;
} 
