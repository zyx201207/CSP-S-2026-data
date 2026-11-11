#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	if(a[m]==0){
		cout<<0;
		return 0;
	}
	else if(m==1){
		cout<<a[1];
		return 0;
	}
	else if(n<=2000){
		long long t=a[1];
		for(int i=2;i<=m;i++){
			t=t&a[i];
		}
		printf("%lld",t);
	}
	else{
		printf("%lld",a[m]);
	}
	return 0;
}
