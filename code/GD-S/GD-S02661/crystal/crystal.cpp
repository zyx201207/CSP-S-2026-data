#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],s[500005];
bool ch(long long x,long long y){
	int ans=1;
	for(int i=1;i<=n-x+1;i++){
		y-=a[x+i-1]*x-s[x+i-1]+s[i-1];
		if(y>=0)return true;
		else y=m;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long r=n+1,l=1;
	while(r-l>1){
		long long mid=(l+r)>>1;
		if(ch(mid,m)){
			l=mid;
		}else r=mid;
	}
	cout<<l;
}
