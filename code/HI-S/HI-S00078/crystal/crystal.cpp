#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long m2=m,m3=m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long m1;
	long long cnt=1;
	for(long long i=1;i<n;i++){
		m1=i*(a[i]-a[i-1]);
		if(m1<=m){
			m-=m1;
			cnt++;
		}else break;
	}
	sort(a,a+n,greater<int>());
	long long cnt2=1;
	for(long long i=1;i<n;i++){
		m1=1*(a[0]-a[i]);
		if(m1<=m2){
			m2-=m1;
			cnt2++;
		}else break;
	}
	cout<<max(cnt,cnt2);
	return 0;
}
