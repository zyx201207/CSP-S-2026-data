#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200001];
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}	
	
	sort(a+1,a+n+1,cmp);

	
	cout<<a[m];
	return 0;
}
