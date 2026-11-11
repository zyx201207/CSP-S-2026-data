#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0,g=0,ms=0;
	long long a[500005]={0};
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		g++;
		s+=g*(a[i]-a[i-1]);
		if(s>1e17){
			s-=1e17;
			m-=1e17;
		}
		while(s>m){
			g--;
			s-=(a[i]-a[i-g]);
		}
		ms=max(ms,g);
	}
	cout<<ms+1;
	return 0;
}
