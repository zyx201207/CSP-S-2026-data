#include<bits/stdc++.h>
using namespace std;
struct r{
	long long x;
	long long y;
}a[10000020];
bool cmp(r x,r y){
	if(x.y!=y.y){
		return x.y>y.y; 
	}
	return x.x>y.x;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i].x;
		long long s=a[i].x;
		while(s>0){
			a[i].y+=s&1;
			s/=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1].x;
	for(long long i=2;i<=k;i++){
		ans=ans&a[i].x;
	}
	cout<<ans;
	return 0;
}
