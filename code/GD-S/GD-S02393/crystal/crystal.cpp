#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(long long i=0;i<=n;i++){
		long long x=0;
		for(long long j=i+1;j<+n;j++){
			x+=a[i]-a[j];
		}
		if(x<=m){
			cout<<n-i;
			return 0;
		}
	}
	return 0;
}
