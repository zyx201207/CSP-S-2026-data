#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,maxn=-500005;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long len=a[2]-a[1],g=1;
	for(int i=n;i>=2;i--){
		if(a[i]-a[i-1]!=len)g=0;
	}
	sort(a+1,a+n+1);
	if(!g){
		maxn=-500005;
		for(int i=1;i<=n;i++)sum+=a[i];
		for(long long i=n;i>=1;i--){
			if(a[i]*i-sum<=m){
				maxn=max(maxn,i);
			}
			sum-=a[i];
		}
		cout<<maxn;
	}else{
		maxn=1;
		long long i=1;
		while(m>=len*i){
			maxn++;
			m-=len*i;
			i++;
		}
		cout<<maxn;
	}
	return 0;
}

