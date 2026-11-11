#include<bits/stdc++.h>
using namespace std;
int n,lujin,ji;
long long d,x[1000000*2];
long long DFS(long long x[],long long m,int j,lujin,zh2){
	long long zhong[n];
	long long ans;
	for(int i=j;i<=n;i++){
		if(a[j]-a[i]<m){
			zhong[i]=DFS(x[1000000*2],m,a[j],lujin+1,zh2);
			if(j>=n-m&&zh2==zhong){
				ans++;
			}
			zh2=min(zh2,zhong[i]);
		}else{
			return;
		}
	}
	if(j>=n-m){
		return ans;
	}
	return lujin;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long x[n+1];
		ji=n;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]<d){
				ji=i;
			}
		}
		long long ans=DFS(x[1000000*2],m,1,0,0);
		if(ans>0){
			cout<<ans;
		}
		else{
			cout<<"0";
		}
	} 
	return 0;
}
