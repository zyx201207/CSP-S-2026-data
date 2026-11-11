#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	int n,m;
	long long sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(int i=2;i<=m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
