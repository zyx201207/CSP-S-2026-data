#include <bits/stdc++.h>
using namespace std ;
const int N = 600500 ;
long long n,m;
long long a[N];
long long s[N];
bool cmp(long long a, long long b){
	return a < b;
}
bool jeged(long long k){
	long long anss = m + 1;
	for(int i = 1 ; i <= n - k + 1; i ++){
		long long sum = s[i + k - 1] - s[i - 1];
		long long tmpp = k*a[i + k - 1] - sum;
		anss = min(tmpp,anss);
	}
	if(anss <= m){	
	 return true;	
	}
	else return false;
}
long long solove(){
	long long l = 1;
	long long r = n;
	long long midd;
	while(l < r){
		midd=(l + r + 1)/2;
		if(jeged(midd)) l = midd;
		else r = midd - 1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long tmpminn = 0 ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		tmpminn = min(tmpminn,a[i]);
	}
	for(int i = 1 ; i <= n ; i ++){
		a[i]-=tmpminn;
	}
	sort(a + 1 , a + n + 1 , cmp);
	for(int i = 1 ; i <= n ; i ++){
		s[i] = s[i - 1] + a[i];
	}
	cout<<solove();
	return 0;
}
//我以为能加又能减，发现的时候已经五点了，警示后人 ，以下为代码  
//5 1000 100 250 500 700 900//		long long avg = sum/k;
//		cout<<avg<<" ";
//		long long lbd = lower_bound(a + 1 , a + k + 1 , avg) - a;
//		cout<<lbd<<" ";
//		long long tmp = (lbd - 1) * avg - s[lbd - 1] + s[i-1];
//		cout<<tmp<<endl;
//		tmp += s[i + k - 1] - s[i - 1] - ((k - lbd + 1) * avg );
//		cout<<tmp<<endl;
//		avg ++ ;
//		lbd = lower_bound(a + 1 , a + k + 1 , avg) - a;
//		long long tmpp = (lbd - 1) * avg - (s[lbd - 1] - s[i-1]);
//		tmpp += s[i + k - 1] - s[i - 1] - ((k - lbd + 1) * avg );
//		anss = min(anss,min(tmp,tmpp));
