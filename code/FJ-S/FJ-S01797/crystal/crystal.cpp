#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010],sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		cout<<a[i]*(i-1)-sum[i-1]<<" ";
		if((a[i]*(i-1)-sum[i-1])>m){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
/*
5 5
1 2 4 8 9
*/