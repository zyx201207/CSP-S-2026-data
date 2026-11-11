#include<bits/stdc++.h>
using namespace std;
long long n,t,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	m=1;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(t>=(a[i+1]-a[i])*i||a[i+1]==a[i]){
			t-=(a[i+1]-a[i])*i;
			m++;
		}
	}cout<<m;
	return 0;
}
