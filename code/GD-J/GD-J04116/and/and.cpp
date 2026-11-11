#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long dp[N],v[N],n,m,ans;
long long xb[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	
	if(n<=20){
		for(int i=1;i<=m;i++){
			xb[i]=i;
		}for(int i=m;i>0;i--){//要动的下标 
			for(int j=i;j<=i+(n-m);j++){//移动到哪里
				long long pd=v[xb[1]];
				xb[i]=j;
				for(int k=2;k<=m;k++){
					pd&=v[xb[k]];
				}ans=max(ans,pd);
				/*
				for(int k=1;k<=m;k++){
					cout<<xb[k]<<" ";
				}cout<<"\n";
				*/
			}
		}cout<<ans;
	}else if(n<=2000){
		if(m==1){
			sort(v+1,v+1+n);
			cout<<v[n];
		}else if(m==n){
			ans=v[1];
			for(int i=2;i<=n;i++){
				ans&=v[i];
			}cout<<ans;
		}else if(m==2){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,v[i]&v[j]);
				}
			}cout<<ans;
		}
	}
	else{
		for(int i=1;i<=m;i++){
			xb[i]=i;
		}for(int i=m;i>0;i--){//要动的下标 
			for(int j=i;j<=i+(n-m);j++){//移动到哪里
				long long pd=v[xb[1]];
				xb[i]=j;
				for(int k=2;k<=m;k++){
					pd&=v[xb[k]];
				}ans=max(ans,pd);
				/*
				for(int k=1;k<=m;k++){
					cout<<xb[k]<<" ";
				}cout<<"\n";
				*/
			}
		}cout<<ans;
	}
	return 0;
}/*
5 3
31 3 1 15 7
*/
