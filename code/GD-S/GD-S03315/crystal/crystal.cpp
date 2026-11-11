#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=0;
	cin>>n>>m;
	for(long long i = 0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i = 1;i<=n;++i){
		b[i]=a[i]-a[i-1];
	}
	long long maxn=0;
	long long l=1,ans=0;
	for(long long i = 1;i<=n;++i){
		++ans;
		if(cnt+b[i]*ans<=m)cnt+=b[i]*ans;
		else {
		  if(maxn<i-l+1)maxn=i-l+1;	
		  ans=0;
		  cnt=0;
		}	
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
