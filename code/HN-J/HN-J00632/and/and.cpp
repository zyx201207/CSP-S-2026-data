#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt;
long long a[2020];
int dfs(long long x,long long p,long long ans){
	if(p==0) return ans;
	for(long long i=x;i<=n-p+1;i++){
		long long c;
		c=a[i];
		c=c&ans;
		c= (long long)c;
		c=dfs(i,p-1,(long long)c);
		ans=max(  ans,   c );
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		 cin>>a[i];
	}
	if(n<=20){
		cnt=dfs(1,m,0);
		cout<<cnt;
	}else{
		if(m==1){
			for(int i=1;i<=m;i++){
				cnt=max(cnt,a[i]);
			}
		}else if(m==2){
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					cnt=max(cnt,a[i]&a[j]);
				}
			}
		}else{
			cnt=a[1];
			for(long long i=2;i<=n;i++){
				cnt=cnt&a[i];
			}
		}
		cout<<cnt;
	}
	return 0;
}
