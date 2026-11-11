#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,ma;
struct num{
	long long v,n;
};
num a[200005];
long long max(long long a,long long b){
	return (a>b?a:b);
}
void dfs(long long b,long long l,long long v){
	if(l==m){
		ma=max(ma,v);
		return;
	}
	if(v<=ma){
		return;
	}
	for(int i=b;i<=n-m+1+l;i++){
		dfs(i+1,l+1,v&a[i].v);
	}
}
long long oneNumber(long long x){
	long long res=0;
	for(;x>0;x=x>>1){
		if(x&1==1){
			res++;
		}
	}
	return res;
}
bool cmp(num a,num b){
	return a.n>b.n;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
		a[i].n=oneNumber(a[i].v);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n-m+1;i++){
		dfs(i+1,1,a[i].v);
	}
	cout<<ma;
	return 0;
}
