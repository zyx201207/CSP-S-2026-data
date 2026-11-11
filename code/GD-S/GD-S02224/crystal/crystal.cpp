#include<bits/stdc++.h>
using namespace std;

long long n=0, m=0, a[500005]={0}, ans=0, qzh[500005]={0};

bool ck(long long h){
	for(int i=h; i<=n; i++){
		long long qjh=qzh[i]-qzh[i-h], mbh=a[i]*h;
		if(mbh-qjh<=m){
			return 1;
		}
	}
	return 0;
}

int fd(){
	long long l=0, r=1e6, mid=(0+1e6)/2;
	while(l<r){
		bool tf=ck(mid);
		if(tf){
			if(!ck(mid+1)){
				return mid;
			}
			l=mid+1;
		}
		else{
			r=mid;
		}
		mid=(l+r)/2;
	}
	return mid;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	ans=fd();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
