#include<bits/stdc++.h>
using namespace std;
long long maxn=-99999999;
long long a[500010];
long long b[500010]; 
long long c[500010];
long long n;
long long m,num,bj1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	b[0]=2;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	num=a[1];
	for(long long i=1;i<=n;i++){
		for(long long j=b[i-1];j<=n&&(num+m+a[j+1])>=a[j]*(j-i+1);j++){
			num+=a[j];
			if((num+m>=a[j]*(j-i+1))) maxn=max(maxn,j-i+1);
			b[i]=j;
		}
		num-=a[i];
		num-=a[b[i]];
	}
	cout<<maxn;
	return 0;
} 
