#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+1000;
long long n,m,a[maxn]={0},sum=-11,r;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(long long i=1;i<=n;i++){
			scanf("%lld",&r);
			sum=max(sum,r);
		}
		cout<<sum;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	cout<<a[m];
	return 0;
}
