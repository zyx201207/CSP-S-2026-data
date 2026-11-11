#include<bits/stdc++.h>
using namespace std;
long long nm[500005],ma=-1;
long long n;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,mi;
	int q=1,w=1;
	cin>>n>>m;
	if(n*n>1e9){
		for(int i=1;i<=n;i++){
			scanf("%lld",&nm[i]);
	}	
	if(m-n>0)cout<<n;
	else{
		cout<<n-m;
	}
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&nm[i]);
	}	
	sort(nm+1,nm+1+n);
	long long cha=nm[n-1]+m-nm[n];
	if(cha<0){
		cout<<1;
		return 0;
	}
	if(cha==0){
		cout<<2;
		return 0;
	}
	for(int i=n;i>=1;i--){
		long long cnt=1;
		int cha=nm[i-1]-nm[i]+m;
		for(int j=i-1;j>=1;j--){
			if(cha<0){
				break;
			}
			if(j!=i-1){
				cha=cha-nm[i]+nm[j];
			}
			
			if(cha<0)break;	
			
			cnt++;
			
	}
	ma=max(ma,cnt);
	cnt=0;
}

	if(ma>n){
		cout<<n;
		return 0;
	}
	cout<<ma;
	
	return 0;
}
