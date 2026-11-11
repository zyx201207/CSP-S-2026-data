#include<bits/stdc++.h>
using namespace std;

long long n,m,ans = 0;
long long a[200007];

long long awa(long long a1,long long a2){
	long long a3 = a1;
	a3 &= a2;
	return a3;
}

int main(){
	freopen("stdin","r",and.in);
	freopen("stdout","r",and.out);
	cin>>n>>m;
	for(long long i = 1;i <= n;i++)cin>>a[i];
	sort(a,a+n+1);
	ans = a[n];
	if(m == 1){
		ans = a[n];
	}else if(m == n){
		ans = a[1];
		for(long long i = 2;i <= n;i++){
			ans = awa(ans,a[i]);
		}
	}
	cout<<ans;
	return 0;
}
