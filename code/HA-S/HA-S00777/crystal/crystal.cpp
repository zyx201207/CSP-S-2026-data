#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long c[1005];
	for(long long i=1;i<=m;i++){
		a[1]+=1;
		sort(a+1,a+1+n);
	}
	long long sum=0;
	for(long long i=1;i<=n-1;i++){
		if(a[i]==a[i+1])sum++;
	}
	cout<<sum+1;
	return 0;
}
