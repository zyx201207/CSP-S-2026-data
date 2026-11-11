#include <bits/stdc++.h>
using namespace std;
__int128 n,m,l=1,an=1,k=1;
long long a[700000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n1,m1;
	cin>>n1>>m1;
	n=n1;
	m=m1;
	for(__int128 i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(__int128 i=2;i<=n;i++){
		m=m-(__int128)(a[i]-a[i-1])*(i-l);
		while(m<0){
			m=m+(a[i]-a[l]);
			l++;
		}
		an=max(an,i-l+1);
	}
	long long an1;
	an1=an;
	cout<<an1;
	return 0;
}
