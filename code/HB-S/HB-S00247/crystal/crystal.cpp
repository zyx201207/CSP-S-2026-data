#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500001]={},ans=1,f;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	f=a[2]-a[1];
	while(1){
		if(m>=ans*f){
			m-=ans*f;
			ans++;
		}
		else break;
	}
	cout<<ans;
	return 0;
}
