#include<bits/stdc++.h>
#include<limits>
using namespace std;
int n;
long long m;
vector<long long>a;
bool check(int x){
	int l=1,r=x;
	long long now=0;
	for(int i=1;i<x;i++){
		now+=a[x]-a[i];
	}
	while(r<=n){
		//printf("seg[%d,%d] is %lld\n",l,r,now);
		if(now<=m&&now>0){
			return true;
		}		
		now=now-(a[r]-a[l])+(a[r+1]-a[r])*(x-1);
		l++;
		r++;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	a.resize(n+1,0);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(&a[1],&a[n]);
	int l=1,r=n,mid,ans=1;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	printf("%d",ans);
}
