#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<=16&&(a[2]-a[1])!=(a[3]-a[2])){
		for(long long i=1;m>=0;i++){
			m-=(a[i+1]-a[i])*i;
			ans++;
		}
	}
	else{
		m/=(a[1]-a[0]);
		long long i=1;
		while((m-=i)>=0) {
			ans++;
			i++;
		}
	}
	cout<<ans;
	return 0;
} 
