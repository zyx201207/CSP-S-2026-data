#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long ans=a[0];
	for(int i=0;i<m;i++){
		ans=ans&a[i];
	}
	printf("%lld",ans);
	return 0;
}
