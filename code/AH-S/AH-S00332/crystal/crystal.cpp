#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500001],qzh[500001];
bool check(int mid){
	for(int ur=mid;ur<=n;ur++){
		int ul_=ur-mid;
		/*From (ul_+1) to ur*/
		long long k=a[ur]*mid-qzh[ur]+qzh[ul_];
		if(k<=m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
