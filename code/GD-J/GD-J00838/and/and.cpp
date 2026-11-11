#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
long long v(long long id){
	long long maxs=0;
	for(int i=id+1;i<=n;i++){
		if(id>m)maxs=max(maxs,a[i]);
		else maxs=max(maxs,a[i]&v(id+1));
	}
	return maxs;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)scanf("%lld",a[i]);
	cout<<v(0);
	return 0;
}

