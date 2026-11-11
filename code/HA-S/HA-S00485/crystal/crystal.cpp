#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n, m, a[100010]={0}, s[100010]={0};
long long max1(long long a, long long b){
	if(a > b) return a;
	return b;
}
long long search(long long l, long long r, long long w){
	long long p=0;
	long long mid = (l+r)/2;
	while(l < r){
		//cout<<1;
		if((s[mid]- s[w+1]) >m && s[mid+1] - s[w+1] < m){
			return w - mid-1;
		}
		if((s[mid]- s[w+1]) <m && s[mid-1] - s[w+1] > m){
			return w - mid+1;
		}
		if((s[mid]- s[w+1]) ==m){
			return mid - w;
		}
		if((s[mid]- s[w+1]) >m){
			l = mid;
		}else{
			r = mid;
		}
	}
	return mid;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	long long al;
	for(int i =1; i<=n; i++){
		cin>>a[i];
		
	}
	sort(a+1, a+n+1);
	for(int i =n; i>=1; i--){
		s[i] = s[i+1] +a[i];
	}
	
	//for(int i =1; i<=n; i++) cout<<a[i];
	long long tot=0;
	for(int i =2; i<=n; i++){
		long long q = m;
		long long p = 0;
		
		for(int j = r; j>=l && q>=(a[i] - a[j]); j--){
			q-=(a[i] - a[j]);
			p++;
		}
		//p = search(1, i, i);
		tot = max1(tot, p);
	}
	cout<<tot;
	return 0;
}
