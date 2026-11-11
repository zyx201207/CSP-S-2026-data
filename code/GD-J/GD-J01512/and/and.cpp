#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
ll n,arr[N],k,m=0;
void sort2(ll x,ll r){
	if(x<0){
		m=r;
		return;
	}
	//cout<<x<<" "<<l<<" "<<r<<endl;
	vector<ll>arr1;
	ll len0=0,len1=0;
	for(int i=1;i<=r;i++){
		if(arr[i]&(1<<x)){
			arr1.push_back(arr[i]);
			len1++;
		}else len0++;
	}
	if(len0==r){
		sort2(x-1,r);
		return;
	}
	if(len1<k){
		sort2(x-1,r);
		return;
	}
	for(int i=1;i<=len1;i++){
		arr[i]=arr1[i-1];
	}
	sort2(x-1,len1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	sort2(31,n);
	ll ans=1<<31;
	ans--;
	if(k>m){
		printf("0");
		return 0;
	}
	for(int i=1;i<=k;i++){
		ans=ans&arr[i];
	}
	printf("%lld",ans);
	return 0;
}
//freopen("or.ans","W",stdin);
