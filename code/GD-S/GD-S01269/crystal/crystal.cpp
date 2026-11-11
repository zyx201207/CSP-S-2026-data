#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s[500100];
long long k[500100];
int check(int p){
	int ans=0;
	for(int i=1;i<=n-p+1;i++){
		long long x=i,y=i+p-1;
		long long pd=s[y]*(p-1)-(s[y-1]-s[x-1]);
		if(pd<=m)ans=1;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		k[i]=k[i-1]+s[i];
	}
	sort(s+1,s+n+1);
	long long l=1,r=n;
	long long maxn=-5; 
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)==1){
			l=mid+1;
			maxn=max(maxn,mid);
		}
		else {
			r=mid-1;
		}
	}
	cout<<maxn;
	return 0;
 } 
