#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s,t=1,maxx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	s/=n;
	sort(a+1,a+n+1);
	/*for(int i=1;i<=n;i++){
		if(a[i]>=s){
			t=i;
			while(a[t]==a[i]) t++;
			t--;
			break;
		}
	}
	for(int i=t-1;i>=1;i--){
		if(m>=a[t]-a[i]){
			m-=a[t]-a[i];
			maxx++;
		}
		else break;
	}*/
	while(m>=(a[t+1]-a[t])*maxx&&maxx<n){
		m-=(a[t+1]-a[t])*maxx;
		maxx++;
		t++;
	}
	cout<<maxx;
	return 0;
}
