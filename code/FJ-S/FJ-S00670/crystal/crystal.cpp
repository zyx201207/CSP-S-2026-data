#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N];
int two(int l,int r){
	if(l==r)return l;
	int mid=(l+r)/2+1;
	long long sum=0;
	for(int i=1;i<mid;i++){
		sum+=(a[mid]-a[i]);
		if(sum>m)return two(l,mid-1);
	}
	//cout<<sum<<' '<<l<<' '<<r<<endl;
	return two(mid,r);
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int k=two(1,n);
	printf("%d",k);
	return 0;
}
