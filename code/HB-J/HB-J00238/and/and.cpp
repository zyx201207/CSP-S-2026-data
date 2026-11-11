#include <bits/stdc++.h>
using namespace std;
long long n,m,ma;
long long a[999999];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ma=a[n];
	m--;
	for(int i=n-1;i>=1;i--){
		if(m==0){
			break;
		}
		ma=ma & a[i];
		m--;
	}
	cout<<ma;
	return 0;
}
