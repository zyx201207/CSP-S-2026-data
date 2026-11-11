#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long mx=-1;
	for(long long i=n;i>=1;i--){
		long long ae=m,j=i;
		for(;ae>=0&&j>=1;j--){
			ae-=a[i]-a[j-1];
		}
		j++;
		if(i-j+1>mx){
			mx=max(i-j+1,mx);
		}
	}
	printf("%lld",mx);
	return 0;
}
//AC
