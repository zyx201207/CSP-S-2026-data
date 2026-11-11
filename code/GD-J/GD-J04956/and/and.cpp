#include<iostream>
#include<algorithm>
using namespace std;
long long a[200010];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long sum=a[1];
	for(int i=2;i<=m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
