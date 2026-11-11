#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	m--;
	for(int i=n;i>1;i--){
		m--;
		x=(a[i]&a[i-1]);
		if(m==0) break;
	}
	cout<<x;
	return 0;
}
