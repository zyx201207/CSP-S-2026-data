#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long n,m,zd=0,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		zd=max(zd,a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=0&&m!=0;i--){
		zd=zd&a[i];
		m--;
	}
	cout<<zd;
	return 0;
}
