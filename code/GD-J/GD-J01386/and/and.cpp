#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m;
long long a[N];
long long sum;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("ans.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(long long i=1;i<=m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
