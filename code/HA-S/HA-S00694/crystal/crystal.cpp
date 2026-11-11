#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[50005];//100000005   100000000000000005      5*10000+5
long long cnt=1;
int cha=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(a+0,a+n);//升序
	cha=a[1]-a[0];
	int q=0;
	while(m>=0) {
		q++;
		m-=cha*q;
		if(m<0) {
			break;
		}
		cnt++;
	}
	cout<<min(cnt,n);
	return 0;
}









