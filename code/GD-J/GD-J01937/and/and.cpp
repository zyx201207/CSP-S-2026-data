#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<long long>num(n+1,0);
	vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
	for(long long i = 1;i<=n;i++){
		scanf("%lld",&num[i]);
	}
	if(m==1){
		for(int i ;i<=n;i++){
			ans=max(ans,num[i]);
		}
	}
	if(m==2){
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			ans = max(ans,(num[i]&num[j]));
		}
	}
}
	cout<<ans;
	return 0;
}
