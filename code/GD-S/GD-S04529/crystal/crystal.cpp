#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	long long sum=0;
	for(int i=2;i<=n;i++){
		sum+=(i-1)*(a[i]-a[i-1]);
		if(sum>m){
			cout <<i-1;
			return 0;
		}
	}
	cout <<n;
	return 0;
}
