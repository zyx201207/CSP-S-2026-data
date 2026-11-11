#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[1000005]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	if(m==1){
		ans=a[n];
	}
	else{
		ans=a[n];
		m--;
		while(m){
			ans=(ans & a[n-m]);
			m--;
		}
	}
	cout<<ans;
	
	
	return 0;
}
