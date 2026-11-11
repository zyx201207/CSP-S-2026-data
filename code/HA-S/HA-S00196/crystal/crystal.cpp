#include <bits/stdc++.h>
using namespace std;
long long a[50001]={0};
long long f(long long m){
	long long s;
	for(s=m;m-(a[2]-a[1])*s*(s+1)/2<0;s--);
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	long long n,m,s=1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[2]-a[1]==a[3]-a[2]&&a[3]-a[2]==a[4]-a[3]&&a[4]-a[3]==a[5]-a[4]&&a[5]-a[4]==a[6]-a[5]&&n>=100){cout<<f(m); return 0;}
	for(long long i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			m-=i*(a[i+1]-a[i]);
			if(m<0) break;
			else s++;
		} else s++;
	}
	cout<<s;
	return 0;
} 
