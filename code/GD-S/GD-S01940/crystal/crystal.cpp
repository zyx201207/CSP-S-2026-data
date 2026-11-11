#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int n,m;
void slove1(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long j=i-1,cnt=1,use=0;
		while(use+(a[i]-a[j])<=m&&j>0)cnt++,use+=a[i]-a[j],j--;
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return;
}
void slove2(){
	long long i=1;
	while(i*(i=1)<=m)i++;
	printf("%lld",i);
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
//	cout<<n<<' ';
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	bool flag=1;
	int base=a[2]-a[1];
	for(int i=1;i<n;i++){
		if(a[i]+base!=a[i+1]){
			flag=0;
			slove1();
			return 0;
		} 
	}
	if(flag)slove2();
	return 0;
}
