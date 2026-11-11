#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long ans=a[n-m+1];
	for(int i=n-m+2;i<=n;i++){
		ans=a[i]&ans;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
