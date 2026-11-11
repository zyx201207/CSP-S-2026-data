#include <bits/stdc++.h>
using namespace std;

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m,a[500005],ans = -814514114514114514;
	cin>>n>>m;
	for(long long i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long i = 0,j = 0;
	while(j<n){
		long long a1 = a[i]-a[j];
		if(m>=a1){
			m-=a1;
			j++;
		}else{
			m+=(a[i]-a[i+1])*(j-i);
			ans = max(ans,j-i);
			i++;
		}
	}
	ans = max(ans,j-i);
	cout<<ans;
	return 0;
}
