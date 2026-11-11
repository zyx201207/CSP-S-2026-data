#include <bits/stdc++.h>
using namespace std;

long long n,m,a[int(2e5+5)];
int duishu(long long n){
	long long x=2;
	int cnt=0;
	while(x<=n){
		x*=2;cnt++;
	}return cnt-1;
}
bool cmp(int x,int y){
	if(duishu(x)!=duishu(y))
		return duishu(x)>duishu(y);
	else return __builtin_popcount(x)>__builtin_popcount(y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++)
		ans&=a[i];
	cout<<ans;
	return 0;
}
