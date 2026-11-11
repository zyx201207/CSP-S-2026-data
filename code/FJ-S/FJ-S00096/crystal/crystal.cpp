#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[600000]; 
long long ans;
void zzd(long long dqs,long long sl){
	for(long long i=1;i<=n;i++){
		if(a[i]==dqs){
			sl++;
		}
	}
	if(sl>=ans){
		ans=sl;
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
	 	cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==0){
		for(long long i=1;i<=n;i++){
			zzd(a[i],0);
		}
		cout<<ans;
		return 0;
	}
	else if(m<=n){
		long long t=1;
		ans=1;
		for(long long i=1;i<=m;i++){
			ans++;
			for(long long j=1;j<=t;j++){
				i++;
			}
			t++;
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<n;
	}
}
