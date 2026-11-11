#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500051];
long long qzh[500051];
long long ans=1;
long long f;
long long cry(long long v){
	if(v-ans<=0){
		return 0;
	}
	if(((ans+1)*a[v]-(qzh[v]-qzh[v-ans-1]))<=m){
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	cin>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]<0){
		f=((a[1])*(-1));
	}
	for(long long i=1;i<=n;i++){
		a[i]+=f;
	}
	for(long long i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	for(long long i=2;i<=n;i++){
		while(cry(i)){
			ans++;
		}
	}
	cout<<ans;
	return 0; 
}
