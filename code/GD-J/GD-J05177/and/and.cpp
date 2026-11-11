#include<bits/stdc++.h>
using namespace std;
long long a[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	if(m==1){
		printf("%lld",a[n-1]);
		return 0;	
	}
	int nn=n-1;
	long long ans=a[nn];
	for(int i=0;i<m-1;i++){
		ans&=a[nn-1];
		nn--;
	}
	printf("%lld",ans);
	return 0;
} 	
