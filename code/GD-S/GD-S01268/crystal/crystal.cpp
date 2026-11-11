#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,maxn=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int j=0;
	sum=m;
	for(int i=1;i<=n;i++){
		if(j<=i){j=i+1;}
		if(i!=1){
			sum+=(a[j-1]-a[i-1]);
		}
		if(j==i+1){sum=m;}
		for(;j<=n;j++){
			if(sum-(j-i)*(a[j]-a[j-1])>=0) sum-=(j-i)*(a[j]-a[j-1]);
			else{
				long long x=j-i;
				maxn=max(maxn,x);
				break;
			}
		}
	}
	cout<<maxn;
	return 0;
} 
