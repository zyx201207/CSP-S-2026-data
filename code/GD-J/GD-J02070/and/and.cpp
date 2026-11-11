#include<iostream>
#include<algorithm>

using namespace std;

long long c[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >>n>>m;
	for(long long i=1;i<=n;i++){
		cin >>c[i];
	}
	sort(c+1,c+n+1);
	if(m==1){
		cout<<c[n];
	}
	long long ans=c[n];
	for(long long i=n-1;i>(n-m);i--){
		ans&=c[i];
	}
	cout<<ans;
	return 0;
}
