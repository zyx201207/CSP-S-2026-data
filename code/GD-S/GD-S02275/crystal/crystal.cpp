#include <bits/stdc++.h>
using namespace std;
long long a[100001];
long long cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen(crystal.in,"r",stdin);
	freopen(crystal.out,"w",stdout);
	long long n,m,x,cnt;
	cin>>n>>m;
	cnt=0;
	x=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	while(m>0){
		sort(a+1,a+n+1,cmp);
		a[1]++;
		m--;
	}
	x=a[1];
	for(long long i=1;i<=n;i++){
		if(a[i]==x){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
